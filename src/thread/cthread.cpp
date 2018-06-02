#include "cthread.h"

Cthread::Cthread(void *(*func)(void *), void *arg)
    : func_(func), arg_(arg) {
    tidp_ = new pthread_t;
}

Cthread::~Cthread() {
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
     std::cout << "cthread join return:" << ret << std::endl;
     return ret;
 }

