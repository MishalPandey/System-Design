#include <iostream>
using namespace std;

/*
===========================================================
CASE 1: NON-VIRTUAL DESTRUCTOR (PROBLEM)
===========================================================
*/

class Base1 {
public:
    Base1() {
        cout << "Base1 Constructor\n";
    }

    // ❌ Not virtual
    ~Base1() {
        cout << "Base1 Destructor\n";
    }
};

class Derived1 : public Base1 {
public:
    int* data;

    Derived1() {
        cout << "Derived1 Constructor\n";
        data = new int[5];  // dynamic memory
    }

    ~Derived1() {
        cout << "Derived1 Destructor\n";
        delete[] data;      // cleanup
    }
};

void testWithoutVirtual() {
    cout << "\n--- Without Virtual Destructor ---\n";

    Base1* obj = new Derived1();
    delete obj;

    /*
    ❗ Output:
       Base1 Constructor
       Derived1 Constructor
       Base1 Destructor

    ❌ Problem:
       Derived1 destructor NOT called
       → memory leak (data not deleted)
    */
}


/*
===========================================================
CASE 2: VIRTUAL DESTRUCTOR (CORRECT)
===========================================================
*/

class Base2 {
public:
    Base2() {
        cout << "Base2 Constructor\n";
    }

    // ✅ Virtual destructor
    virtual ~Base2() {
        cout << "Base2 Destructor\n";
    }
};

class Derived2 : public Base2 {
public:
    int* data;

    Derived2() {
        cout << "Derived2 Constructor\n";
        data = new int[5];
    }

    ~Derived2() {
        cout << "Derived2 Destructor\n";
        delete[] data;
    }
};

void testWithVirtual() {
    cout << "\n--- With Virtual Destructor ---\n";

    Base2* obj = new Derived2();
    delete obj;

    /*
    ✅ Output:
       Base2 Constructor
       Derived2 Constructor
       Derived2 Destructor
       Base2 Destructor

    ✔ Proper cleanup happens
    */
}


/*
===========================================================
CASE 3: ABSTRACT CLASS (REAL INTERVIEW USE)
===========================================================
*/

class Shape {
public:
    Shape() {
        cout << "Shape Constructor\n";
    }

    // ✅ Pure virtual function → makes class abstract
    virtual void draw() = 0;

    // ✅ Always keep destructor virtual in abstract class
    virtual ~Shape() {
        cout << "Shape Destructor\n";
    }
};

class Circle : public Shape {
public:
    int* buffer;

    Circle() {
        cout << "Circle Constructor\n";
        buffer = new int[10];
    }

    void draw() override {
        cout << "Drawing Circle\n";
    }

    ~Circle() {
        cout << "Circle Destructor\n";
        delete[] buffer;
    }
};

void testAbstractClass() {
    cout << "\n--- Abstract Class Example ---\n";

    Shape* obj = new Circle();  // base pointer
    obj->draw();
    delete obj;

    /*
    ✅ Output:
       Shape Constructor
       Circle Constructor
       Drawing Circle
       Circle Destructor
       Shape Destructor
    */
}


/*
===========================================================
MAIN
===========================================================
*/

int main() {
    testWithoutVirtual();
    testWithVirtual();
    testAbstractClass();
    return 0;
}