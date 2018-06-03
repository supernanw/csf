#ifndef CRWLOCK_H_
#define CRWLOCK_H_

#include <pthread.h>

class Crwlock {
public:
    Crwlock();
    virtual ~Crwlock();

    int Rdlock();
    int TryRdlock();
    int Wrlock();
    int TryWrlock();
    int Unlock();

private:
    pthread_rwlock_t rwlock_;
};

#endif // CRWLOCK_H_
