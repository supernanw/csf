#include "cthread.h"
using namespace std;

Cthread::Cthread(void *(*func)(void *), void* arg)
    : func_(func), arg_(arg) {}

Cthread::~Cthread() {}

int Cthread::Start() {
    return pthread_create(&tidp_, NULL, func_, arg_);
}
 
int Cthread::Join(void** rval_ptr) {
    int ret = pthread_join(tidp_, rval_ptr);
    if (*rval_ptr == PTHREAD_CANCELED) {
        std::cout << "cthread canceled" << std::endl;
        ret = -1;
    }
    return ret;
}

int Cthread::Stop() {
    return pthread_cancel(tidp_);
}

unsigned int Cthread::ThreadID() {
    return (unsigned int)pthread_self();
}
