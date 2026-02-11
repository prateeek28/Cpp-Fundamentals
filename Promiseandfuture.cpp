
/*
Topic: FUTURE AND PROMISE
--> They are used for one-time communication between threads.

-> One thread produces a value
-> Another thread consumes the value

Think of it like this:

promise = “I will give you a value later”
future = “I’ll wait and receive that value”

Q. Why do we need them?

Because:

Threads don’t return values directly

Global variables are unsafe

Condition variables are complex

future & promise solve this cleanly

Basic Flow (IMPORTANT)
Thread A → promise.set_value()
             
Thread B → future.get()


promise sets the result

future gets the result

*/


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

/**
 * @brief Function executed in a separate thread.
 *
 * This function calculates a value
 * and sets it inside the promise.
 *
 * @param p Promise object used to send result.
 */
void add(std::promise<int> p) {

    int result = 10 + 20;

    /**
     * set_value() stores the result inside promise.
     * The associated future will receive this value.
     */
    p.set_value(result);
}

/**
 * @brief Entry point of the program.
 *
 * Demonstrates:
 * - Creating promise and future
 * - Passing promise to a thread
 * - Receiving value using future
 */
int main() {

    /// Step 1: Create promise
    std::promise<int> p;

    /**
     * Step 2: Get future from promise.
     * future is linked to this promise.
     */
    std::future<int> f = p.get_future();

    /**
     * Step 3: Start thread and move promise into it.
     *
     * Important:
     * promise cannot be copied,
     * so we use std::move().
     */
    std::thread t(add, std::move(p));

    /**
     * Step 4: Get the result.
     *
     * get():
     * - Waits until value is available
     * - Returns the value
     */
    cout << "Result: " << f.get() << endl;

    t.join();

    return 0;
}

/*
----------------------------------------
WHY USE future & promise?
----------------------------------------

1. Threads cannot directly return values.
2. Global variables are unsafe.
3. Condition variables are more complex.

future & promise provide:
✔ Safe communication
✔ Clean design
✔ Automatic synchronization

----------------------------------------
REAL-WORLD ANALOGY
----------------------------------------

promise  → "I will give you the result later."
future   → "Okay, I will wait and receive it."

Producer thread sets value.
Consumer thread gets value.
*/
