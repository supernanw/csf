#ifndef CCOND_H_
#define CCOND_H_

#include <pthread.h>
#include <sys/time.h>

class Ccond {
public:
    Ccond();
    virtual ~Ccond();

    int Lock();
    int TryLock();
    int Unlock();

    int Wait();
    int TimedWait(const struct timespec* timeout);
    int TimedWait(time_t seconds, long nanoseconds=0);
    int Signal();
    int Broadcast();

private:
    pthread_mutex_t* mutex_;
    pthread_cond_t* cond_;
};

#endif // CCOND_H_
