#include<iostream>
#include <mutex>

using namespace std;

class Singleton {
private:
    static Singleton* instance;
    static mutex mtx;

    Singleton() { 
        cout << "Singleton Constructor Called!" << endl; 
    }
 
public:
    static Singleton* getInstance() {
        lock_guard<mutex> lock(mtx); // Lock for thread safety
        if (instance == nullptr) {
            instance = new Singleton();
        }
         return instance;
    }
};
 
// Initialize static members
Singleton* Singleton::instance = nullptr;
mutex Singleton::mtx;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    cout << (s1 == s2) << endl;
}
// maanlete 2 alag alag system ne ek hi baar ek hi time pe exact Singleton::getInstance(); call kiya us time ke liye

// mutex is used to ensure that only one thread can access the getInstance() method at a time,
// preventing multiple instances from being created in a multi-threaded environment.
//----Matlab ek time me ek thread ko getInstance() method access karne dega,
//----jab tak ki us thread ka kaam complete nahi ho jata, tab tak dusre thread ko wait karna padega.
// lock_guard is a C++ RAII wrapper for mutexes that automatically releases the lock when it goes out of scope.



// Note: This implementation can lead to performance issues due to locking every time getInstance() is called.