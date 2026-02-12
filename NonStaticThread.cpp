/**
 * @file thread_member_function_example.cpp
 * @brief Demonstrates how to use member functions with std::thread.
 *
 * This file shows:
 * 1. How to use a non-static member function with std::thread.
 * 2. How to use a static member function with std::thread.
 *
 */

#include <iostream>
#include <thread>

using namespace std;

class base {
public:

    
    void run(int x) {
        while (x-- > 0) {
            cout << "Non-static: " << x << endl;
        }
    }

    static void staticRun(int x) {
        while (x-- > 0) {
            cout << "Static: " << x << endl;
        }
    }
};

int main() {

    base b;

    thread t1(&base::run, &b, 5);
    t1.join();
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
1. If you forget to pass object for non-static function,
you will get a compilation error.
2. Static member functions behave like normal functions
when used with std::thread.
*/
