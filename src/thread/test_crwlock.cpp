#include <vector>
#include <iostream>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "crwlock.h"

using namespace std;

int main(int argc, char *argv[]) {
    int ret = 0;
    Crwlock rwlock = Crwlock();
    rwlock.Rdlock();
    cout << "rdlock" << endl;

    ret = rwlock.TryWrlock();
    cout << "try wrlock after rdlock, ret:" << strerror(ret) << endl;

    ret = rwlock.TryRdlock();
    cout << "try rdlock after rdlock, ret:" << strerror(ret) << endl;

    rwlock.Unlock();
    rwlock.Unlock();

    rwlock.Wrlock();
    ret = rwlock.TryRdlock();
    cout << "try rdlock after wrlock, ret:" << strerror(ret) << endl;
    rwlock.Unlock();
}
