#include "crwlock.h"

Crwlock::Crwlock() {
    pthread_rwlock_init(&rwlock_, NULL);
}

Crwlock::~Crwlock() {
    pthread_rwlock_destroy(&rwlock_);
}

int Crwlock::Rdlock() {
    return pthread_rwlock_rdlock(&rwlock_);
}

int Crwlock::TryRdlock() {
    return pthread_rwlock_tryrdlock(&rwlock_);
}

int Crwlock::Wrlock() {
    return pthread_rwlock_wrlock(&rwlock_);
}

int Crwlock::TryWrlock() {
    return pthread_rwlock_trywrlock(&rwlock_);
}

int Crwlock::Unlock() {
    return pthread_rwlock_unlock(&rwlock_);
}
