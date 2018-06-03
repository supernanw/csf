#include "cthread.h"
#include "ccond.h"

using namespace std;

bool has_work = false;

void* DoWork(void* arg) {
    Ccond* cond = (Ccond*)arg;
    cond->Lock();
    while (not has_work) {
        cout << "wait, thread id:" << Cthread::ThreadID() << endl;
        cond->Wait();
    }
    cout << "do work, thread id:" << Cthread::ThreadID() << endl;
    cond->Unlock();
}

int main(int argc, char *argv[]) {
    Ccond cond;
    Cthread cthread = Cthread(&DoWork, (void *)&cond);
    cthread.Start();
    cout << "main thread id:" << Cthread::ThreadID() << endl;
    sleep(1);
    cond.Lock();
    has_work = true;
    cout << "main thread add work, id:" << Cthread::ThreadID() << endl;
    cond.Unlock();
    sleep(1);
    cout << "main thread unlock, id:" << Cthread::ThreadID() << endl;
    cond.Signal();
    cout << "main thread Signal, id:" << Cthread::ThreadID() << endl;
    sleep(1);
    void * rval;
    cthread.Join(&rval);
}
