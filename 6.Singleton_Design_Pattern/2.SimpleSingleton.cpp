#include<iostream>

using namespace std;

class Singleton {
private:
    static Singleton* instance;

    Singleton() {
        cout << "Singleton Constructor called" << endl;
    }

public:
    static Singleton* getInstance() {
        if(instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
};

// Initialize static member
Singleton* Singleton::instance = nullptr;
// In C++ static member ko initialize class ke andar nhi karsakte.
// static member bina object banaye bhi access kiya ja sakta hai.

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
    // Output will be 1 (true) since both s1 and s2 point to the same instance
    // it is a Singleton class
}