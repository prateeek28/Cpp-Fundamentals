/**
 * @file dynamic_cast_example.cpp
 * @brief Demonstrates usage of dynamic_cast in C++.
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

/**
 * @class base
 * @brief Base class with a virtual function.
 *
 * Having at least one virtual function makes
 * this class polymorphic, which is required
 * for dynamic_cast to work properly.
 */
class base {
public:
    virtual void print() {
        cout << "base" << endl;
    }
};

/**
 * @class child1
 * @brief Derived class from base.
 */
class child1 : public base {
public:
    void print() override {
        cout << "Child 1" << endl;
    }
};

/**
 * @class child2
 * @brief Another derived class from base.
 */
class child2 : public base {
public:
    void print() override {
        cout << "Child 2" << endl;
    }
};

/**
 * @brief Entry point of the program.
 *
 * Demonstrates:
 * - Successful upcasting
 * - Failed downcasting (pointer)
 * - Failed downcasting (reference)
 */
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

3. If pointer cast fails → returns nullptr.

4. If reference cast fails → throws std::bad_cast.

5. It has runtime overhead because it uses RTTI
   (Run-Time Type Information).

6. If you are 100% sure about the type,
   use static_cast instead (faster).

Synatax :- dynamic_cast < new_type > (expression) 

1. dynamic cast is used at run time to find out correct down_cast
2. it need atleat one virtual function in base class
3. if the cast is successful, dynamic_cast returns a null pointer of that type
4. if the cast fails and the new type is pointer type then it returns a null pointer of that type
5. if the cast fails and new type is a refrence type,
it throws an exception that matches a handler of type std::bad_cast.

1. work only with polymorphic base class(at least one virtual function in base class)
   because it uses this information to decide about wrong down_cast.
2. it is used for up-cast (c->b) and down cast (b->c), but it is mainly used for correct down_cast.
3. using this cast has run time overhead,
 because it checks object type at run time using RTTI (run time type information)
4.if we are sure that we will never cast to wrong object then u should use static cast.
*/

