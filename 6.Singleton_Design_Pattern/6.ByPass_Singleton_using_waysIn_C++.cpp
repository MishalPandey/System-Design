#include <iostream>
using namespace std;

class Singleton {
private:
    // 🔸 Static pointer → holds the single instance
    static Singleton* instance;

    // 🔸 Private constructor → prevents direct object creation
    Singleton() {
        cout << "Singleton instance created\n";
    }

    // ❌ 1. Prevent Copy Constructor
    // Without this:
    // Singleton* s2 = new Singleton(*s1);
    // → creates a new object (breaks Singleton)
    Singleton(const Singleton&) = delete;

    // ❌ 2. Prevent Copy Assignment
    // Without this:
    // Singleton s2;
    // s2 = *s1;
    // → copies state into another object
    Singleton& operator=(const Singleton&) = delete;

    // ❌ 3. Prevent Move Constructor (C++11+)
    // Without this:
    // Singleton s2 = std::move(*s1);
    // → creates a new object using move semantics
    Singleton(Singleton&&) = delete;

    // ❌ 4. Prevent Move Assignment
    Singleton& operator=(Singleton&&) = delete;

protected:
    // ❌ 5. Prevent Cloning via inheritance
    // If constructor was protected, child class could create objects
    // Keeping constructor private blocks subclassing-based cloning

public:
    // 🔸 Global access point
    static Singleton* getInstance() {
        // ❗ Not thread-safe (important limitation)
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }

    void show() {
        cout << "Using Singleton instance\n";
    }

    // ❌ 6. Prevent manual deletion (optional design choice)
    // If destructor is public, someone can delete instance and recreate
    // Making it protected/private can prevent misuse
    ~Singleton() {
        cout << "Singleton destroyed\n";
    }
};

// 🔸 Static member initialization
Singleton* Singleton::instance = nullptr;

int main() {
    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    // ✔ Same address → only one instance
    cout << s1 << endl;
    cout << s2 << endl;

    // ❌ All below are blocked:

    // Singleton* s3 = new Singleton();        // private constructor
    // Singleton s4 = *s1;                     // copy constructor deleted
    // Singleton s5;
    // s5 = *s1;                               // assignment deleted
    // Singleton s6 = move(*s1);               // move constructor deleted

    return 0;
}