#include <iostream>
#include "singleton.h"

using namespace std;

class OneObj {
public:
    friend class Singleton<OneObj>;
    void print() {
        cout << "OneObj print" << endl;
    }

protected:
    OneObj() {
        cout << "OneObj::OneObj" << endl;
    };
    OneObj(const OneObj&) {};
    OneObj& operator=(const OneObj&) {};
};

int main(int argc, char *argv[]) {
    cout << "main start" << endl;
    Singleton<OneObj>::instance().print();
}
