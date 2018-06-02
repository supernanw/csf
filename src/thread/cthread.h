#ifndef CTHREAD_H_
#define CTHREAD_H_

#include <iostream>
#include <pthread.h>

class Cthread {
public:
    Cthread(void* (*func)(void*), void* arg);
    virtual ~Cthread();

    int Start();

    int Join(void** rval_ptr);

private:
    void* (*func_)(void*);
    void* arg_;
    pthread_t* tidp_;
};

#endif // CTHREAD_H_
