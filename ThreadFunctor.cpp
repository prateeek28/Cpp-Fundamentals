/**
 * @file FunctorThreadExample.cpp
 * @brief Demonstrates usage of a functor (function object) with std::thread.
 *
 * This program shows how a class with overloaded operator()
 * can be used as a callable object inside a thread.
 */

#include <iostream>
#include <thread>
using namespace std;

class Base {
public:

    /**
     * Function call operator.
     * This function will execute inside a separate thread.
     * x Number of iterations to print.
     */
    void operator()(int x) {
        while (x-- > 0) {
            cout << x << endl;
        }
    }
};

int main() {
    thread t(Base(), 10);
    t.join();

    return 0;
}


/**
 * WhyFunctor Why use a functor in threads?
 *
 * - Allows encapsulation of logic inside a class.
 * - Can maintain internal state if needed.
 * - Cleaner than using global functions in large projects.
 *
 * NOTE:- Alternatives to functor:
 * - Function pointer
 * - Lambda expression
 * - Member function with object reference
 */
