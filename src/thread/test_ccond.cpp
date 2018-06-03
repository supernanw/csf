#include <iostream>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include "ccond.h"

using namespace std;

int main(int argc, char *argv[]) {
    int ret = 0;
    struct timeval now;
    Ccond cond = Ccond();
    gettimeofday(&now, NULL);
    cout << "timewait start:" << ctime(&now.tv_sec) << endl;
    cond.TimedWait(10);
    gettimeofday(&now, NULL);
    cout << "timewait finish:" << ctime(&now.tv_sec) << endl;
}

