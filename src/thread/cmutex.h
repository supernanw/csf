#ifndef CMUTEX_H_
#define CMUTEX_H_

#include <pthread.h>

class Cmutex {
public:
    Cmutex();
    virtual ~Cmutex();

    int Lock();
    int TryLock();
    int Unlock();

private:
    pthread_mutex_t mutex_;
};

#endif // CMUTEX_H_
