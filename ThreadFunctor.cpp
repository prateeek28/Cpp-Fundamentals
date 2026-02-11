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

/**
 * @class Base
 * @brief Functor class that acts like a function.
 *
 * The operator() is overloaded so that objects of this class
 * can be invoked like a function.
 */
class Base {
public:

    /**
     * @brief Function call operator.
     *
     * This function will execute inside a separate thread.
     *
     * @param x Number of iterations to print.
     */
    void operator()(int x) {
        while (x-- > 0) {
            cout << x << endl;
        }
    }
};


/**
 * @brief Entry point of the program.
 *
 * Creates a thread using a functor object.
 * The thread executes the overloaded operator() function.
 */
int main() {

    /**
     * @brief Creating a thread using a temporary functor object.
     *
     * Syntax explanation:
     * - Base() → temporary object of Base class
     * - 10     → argument passed to operator()
     */
    thread t(Base(), 10);

    /**
     * @brief Waits for the thread to finish execution.
     *
     * join() blocks the main thread until 't' completes.
     */
    t.join();

    return 0;
}


/**
 * @section WhyFunctor Why use a functor in threads?
 *
 * - Allows encapsulation of logic inside a class.
 * - Can maintain internal state if needed.
 * - Cleaner than using global functions in large projects.
 *
 * @note Alternatives to functor:
 * - Function pointer
 * - Lambda expression
 * - Member function with object reference
 */
