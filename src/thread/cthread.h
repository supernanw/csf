#ifndef CTHREAD_H_
#define CTHREAD_H_

#include <iostream>
#include <pthread.h>
#include "unistd.h"

class Cthread {
public:
    Cthread(void* (*func)(void*), void* arg);
    virtual ~Cthread();

    int Start();
    int Join(void **rval_ptr);
    int Stop();

    static unsigned int ThreadID();

private:
    pthread_t tidp_;
    void* (*func_)(void*);
    void* arg_;
    void** rval_ptr_;
};

#endif // CTHREAD_H_
