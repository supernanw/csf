#ifndef SINGLETON_H_
#define SINGLETON_H_
#include <iostream>

using namespace std;

/* 
 * Boost implement
 */
template<typename T>
class Singleton {
private:
    struct ObjectCreator {
        ObjectCreator() {
            cout << "ObjectCreator" << endl;
            Singleton<T>::instance();
        };
        inline void do_nothing() const {};
    };
    static ObjectCreator object_creator;

    Singleton();
    Singleton(const Singleton&);
    Singleton& operator=(const Singleton&);

public:
    static T& instance() {
        cout << "instance" << endl;
        static T object;
        object_creator.do_nothing();
        return object;
    }
    virtual ~Singleton();
};

template<typename T> class Singleton<T>::ObjectCreator Singleton<T>::object_creator;

#endif // SINGLETON_H_
