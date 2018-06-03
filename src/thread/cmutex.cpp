#include "cmutex.h"

Cmutex::Cmutex() {
    mutex_ = new pthread_mutex_t;
    pthread_mutex_init(mutex_, NULL);
}

Cmutex::~Cmutex() {
    pthread_mutex_destroy(mutex_);
}

int Cmutex::Lock() {
    return pthread_mutex_lock(mutex_);
}

int Cmutex::TryLock() {
    return pthread_mutex_trylock(mutex_);
}

int Cmutex::Unlock() {
    return pthread_mutex_unlock(mutex_);
}
