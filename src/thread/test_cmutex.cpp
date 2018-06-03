#include <vector>
#include "unistd.h"
#include "cmutex.h"
#include "cthread.h"

using namespace std;

class Number {
public:
    Number() : num_(0) {
        mutex_ = new Cmutex; 
    }
    ~Number() {
        delete mutex_; 
    }

    void PlusOne() {
        mutex_->Lock();
        cout << "begin num:" << num_ << endl;
        num_ += 1;
        sleep(1);
        cout << "finish num:" << num_ << endl;
        mutex_->Unlock();
    }

    void PrintNum() {
        cout << "num:" << num_ << endl;
    }

private:
    int num_;
    Cmutex* mutex_;
};


void* Func(void* arg) {
    Number* num = (Number*) arg;
    for (int i = 0; i < 5; i++) {
        num->PlusOne();
    }
}

int main(int argc, char *argv[]) {
    Number* num = new Number;
    vector<Cthread*> threads;
    for (int i = 0; i < 2; ++i) {
        Cthread* thread = new Cthread(&Func, (void *)num);
        threads.push_back(thread);
    }
    cout << "create" << endl;

    for(vector<Cthread*>::iterator it = threads.begin();
        it != threads.end(); it++) {
        (*it)->Start();
    }
    cout << "start" << endl;

    sleep(10);

    for(vector<Cthread*>::iterator it = threads.begin();
        it != threads.end(); it++) {
        (*it)->Stop();
        delete (*it);
    }
    cout << "stop" << endl;
    num->PrintNum();
    delete num;
}
