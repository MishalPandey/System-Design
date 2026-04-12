#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = new Singleton();

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}

//  In this implementation, the Singleton instance is created at the time of class loading,
//  ensuring thread safety without the need for synchronization.
//  However, it may lead to resource wastage if the instance is never used.