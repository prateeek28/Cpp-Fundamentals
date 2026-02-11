/**
 * @file thread_member_function_example.cpp
 * @brief Demonstrates how to use member functions with std::thread.
 *
 * This file shows:
 * 1. How to use a non-static member function with std::thread.
 * 2. How to use a static member function with std::thread.
 *
 * Important:
 * - Non-static functions require an object instance.
 * - Static functions do NOT require an object.
 */

#include <iostream>
#include <thread>

using namespace std;

/**
 * @class base
 * @brief Demonstrates thread usage with member functions.
 */
class base {
public:

    /**
     * @brief Non-static member function.
     *
     * Requires an object instance to be called.
     *
     * @param x Number of times to print.
     */
    void run(int x) {
        while (x-- > 0) {
            cout << "Non-static: " << x << endl;
        }
    }

    /**
     * @brief Static member function.
     *
     * Does NOT require an object instance.
     *
     * @param x Number of times to print.
     */
    static void staticRun(int x) {
        while (x-- > 0) {
            cout << "Static: " << x << endl;
        }
    }
};

/**
 * @brief Entry point of the program.
 *
 * Demonstrates both:
 * - Non-static member function thread
 * - Static member function thread
 */
int main() {

    base b;

    /**
     * ---------------------------------------
     * NON-STATIC MEMBER FUNCTION IN THREAD
     * ---------------------------------------
     *
     * Syntax:
     * std::thread t(&ClassName::functionName, &object, arguments);
     *
     * We must pass:
     * 1. Address of member function
     * 2. Address of object
     * 3. Function arguments
     */
    thread t1(&base::run, &b, 5);
    t1.join();

    /**
     * ---------------------------------------
     * STATIC MEMBER FUNCTION IN THREAD
     * ---------------------------------------
     *
     * Since the function is static,
     * it behaves like a normal function.
     *
     * No object is required.
     */
    thread t2(&base::staticRun, 5);
    t2.join();

    return 0;
}

/*
----------------------------------------
KEY DIFFERENCE
----------------------------------------

1. Non-static function:
   - Belongs to object
   - Requires object address
   - Has access to non-static members

2. Static function:
   - Belongs to class
   - No object required
   - Cannot access non-static members

----------------------------------------
BOTTOM LINE
----------------------------------------

If you forget to pass object for non-static function,
you will get a compilation error.

Static member functions behave like normal functions
when used with std::thread.
*/
