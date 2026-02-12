/**
 * @file dynamic_cast_example.cpp
 * Demonstrates usage of dynamic_cast in C++.
 *
 * This example shows:
 * - Safe downcasting using dynamic_cast
 * - Behavior when cast fails (pointer vs reference)
 * - Requirement of polymorphic base class
 *
 * Important:
 * dynamic_cast works only when the base class
 * has at least one virtual function.
 */

#include <iostream>
#include <exception>
using namespace std;

class base {
public:
    virtual void print() {
        cout << "base" << endl;
    }
};

class child1 : public base {
public:
    void print() override {
        cout << "Child 1" << endl;
    }
};
class child2 : public base {
public:
    void print() override {
        cout << "Child 2" << endl;
    }
};

int main() {

    child1 c1;

    /**
     * Upcasting (safe and automatic):
     * child1 → base
     *
     * dynamic_cast is not required here,
     * but used just for demonstration.
     */
    base* bptr = dynamic_cast<base*>(&c1);

    /**
     * Downcasting attempt:
     * base* → child2*
     *
     * This will FAIL because the actual object
     * is of type child1, not child2.
     *
     * When pointer cast fails:
     * dynamic_cast returns nullptr.
     */
    child2* c3 = dynamic_cast<child2*>(bptr);

    if (c3 == nullptr) {
        cout << "Pointer cast failed (NULL returned)" << endl;
    } else {
        cout << "Pointer cast succeeded" << endl;
    }

    /**
     * Downcasting using reference:
     *
     * When reference cast fails,
     * dynamic_cast throws std::bad_cast.
     */
    try {
        child2& r = dynamic_cast<child2&>(c1);
    }
    catch (std::exception& e) {
        cout << "Reference cast failed: " << e.what() << endl;
    }

    return 0;
}

/*
----------------------------------------
BOTTOM LINE
----------------------------------------

1. dynamic_cast works only with polymorphic classes
   (base must have at least one virtual function).
2. Used mainly for safe downcasting.
3. If pointer cast fails -> returns nullptr.
4. If reference cast fails -> throws std::bad_cast.
5. It has runtime overhead because it uses RTTI
  (Run-Time Type Information).
6. If you are 100% sure about the type,
   use static_cast instead (faster).
Synatax :- dynamic_cast < new_type > (expression) 

