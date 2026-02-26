
/**
 * @file future_promise_example.cpp
 * @brief Demonstrates std::promise and std::future in C++.
 *
 * future and promise are used for one-time communication
 * between two threads.
 *
 * Concept:
 * - promise → sets a value (producer)
 * - future  → gets the value (consumer)
 *
 * They provide a clean and safe way to pass results
 * from one thread to another.
 */

#include <iostream>
#include <thread>
#include <future>
using namespace std;

void add(std::promise<int> p) {

    int result = 10 + 20;

    p.set_value(result);
}

int main() {

    /// 1: Create promise
    std::promise<int> p;

    /**
     * 2: Get future from promise.
     * future is linked to this promise.
     */
    std::future<int> f = p.get_future();

    /**
     * 3: Start thread and move promise into it.
     * Important:
     * promise cannot be copied,
     * so we use std::move().
     */
    std::thread t(add, std::move(p));

    /**
     * 4: Get the result.
     * get():
     * - Waits until value is available
     * - Returns the value
     */
    cout << "Result: " << f.get() << endl;

    t.join();

    return 0;
}

/*
WHY USE future & promise?
1. Threads cannot directly return values.
2. Global variables are unsafe.
3. Condition variables are more complex.

future & promise provide:
-> Safe communication
-> Clean design
-> Automatic synchronization

REAL-WORLD ANALOGY:

promise  -> "I will give you the result later."
future   -> "Okay, I will wait and receive it."

Producer thread sets value.
Consumer thread gets value.
*/
