#include "cthread.h"
using namespace std;

Cthread::Cthread(void *(*func)(void *), void* arg)
    : func_(func), arg_(arg) {
    tidp_ = new pthread_t;
}

Cthread::~Cthread() {
    cout << "cthread destruct" << endl;
    delete tidp_;
}

int Cthread::Start() {
    std::cout << "cthread start" << std::endl;  
    int ret = pthread_create(tidp_, NULL, func_, arg_);
    std::cout << "cthread start return:" << ret << std::endl;  
    return ret;
}
 
int Cthread::Join(void** rval_ptr) {
    std::cout << "cthread join" << std::endl;
    int ret = pthread_join(*tidp_, rval_ptr);
    if (*rval_ptr == PTHREAD_CANCELED) {
        std::cout << "cthread canceled" << std::endl;
        ret = -1;
    }
    std::cout << "cthread join return:" << ret << std::endl;
    return ret;
}

int Cthread::Stop() {
    std::cout << "cthread Stop" << std::endl;
    int ret = pthread_cancel(*tidp_);
    std::cout << "cthread Stop return:" << ret << std::endl;
    return ret;
}
