#include "ccond.h"

Ccond::Ccond() {
   mutex_ = new pthread_mutex_t;
   cond_ = new pthread_cond_t;
   pthread_mutex_init(mutex_, NULL);
   pthread_cond_init(cond_, NULL);
}

Ccond::~Ccond() {
    pthread_cond_destroy(cond_);
    pthread_mutex_destroy(mutex_);
    delete cond_;
    delete mutex_;
}

int Ccond::Wait() {
    return pthread_cond_wait(cond_, mutex_);
}

int Ccond::TimedWait(const struct timespec* timeout) {
    return pthread_cond_timedwait(cond_, mutex_, timeout); 
}

int Ccond::TimedWait(time_t seconds, long nanoseconds) {
    struct timeval now;
    gettimeofday(&now, NULL);
    struct timespec timeout;
    timeout.tv_sec = now.tv_sec + seconds;
    timeout.tv_nsec = now.tv_usec * 1000 + nanoseconds;
    return pthread_cond_timedwait(cond_, mutex_, &timeout); 
}
