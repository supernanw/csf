#include "ccond.h"

Ccond::Ccond() {
   pthread_mutex_init(&mutex_, NULL);
   pthread_cond_init(&cond_, NULL);
}

Ccond::~Ccond() {
    pthread_cond_destroy(&cond_);
    pthread_mutex_destroy(&mutex_);
}

int Ccond::Lock() {
    return pthread_mutex_lock(&mutex_);
}

int Ccond::TryLock() {
    return pthread_mutex_trylock(&mutex_);
}

int Ccond::Unlock() {
    return pthread_mutex_unlock(&mutex_);
}
int Ccond::Wait() {
    return pthread_cond_wait(&cond_, &mutex_);
}

int Ccond::TimedWait(const struct timespec* timeout) {
    return pthread_cond_timedwait(&cond_, &mutex_, timeout); 
}

int Ccond::TimedWait(time_t seconds, long nanoseconds) {
    struct timeval now;
    gettimeofday(&now, NULL);
    struct timespec timeout;
    timeout.tv_sec = now.tv_sec + seconds;
    timeout.tv_nsec = now.tv_usec * 1000 + nanoseconds;
    return pthread_cond_timedwait(&cond_, &mutex_, &timeout); 
}

int Ccond::Signal() {
    return pthread_cond_signal(&cond_);
}

int Ccond::Broadcast() {
    return pthread_cond_broadcast(&cond_);
}
