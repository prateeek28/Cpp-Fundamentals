/**
 * UniqueLockExample.cpp
 *
 * Simple example to understand how std::unique_lock works with std::mutex.
 *
 * What this program shows:
 * - How to protect shared data using a mutex.
 * - How deferred locking works.
 * - Why unique_lock is more flexible than lock_guard.
 */

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

// This mutex protects the shared variable below.
std::mutex m1;

// This is the shared data both threads will modify.
int buffer = 0;


/*
 * This function runs in multiple threads.
 * Each thread increments the shared buffer.
 */
void task(const char* threadnumber, int loopfor) {

    /*
     * We are creating a unique_lock,
     * but we are NOT locking the mutex yet.
     *
     * std::defer_lock means:
     * Create the lock object, but don’t lock the mutex now.
     * I will lock it manually later.
     */
    std::unique_lock<std::mutex> lock(m1, std::defer_lock);

    // Code here runs without locking.
    // You can do non-critical work here safely.

    // Now we manually lock the mutex.
    lock.lock();

    /*
     * Critical section starts here.
     * Only one thread at a time can enter this part.
     */
    for (int i = 0; i < loopfor; ++i) {
        buffer++;
        std::cout << threadnumber << " " << buffer << std::endl;
    }

    /*
     * No need to call unlock().
     * When 'lock' goes out of scope,
     * its destructor automatically unlocks the mutex.
     *
     * This is RAII (Resource Acquisition Is Initialization).
     */
}

int main() {

    // Creating two threads that run the same function.
    std::thread t1(task, "t1", 5);
    std::thread t2(task, "t2", 5);

    // Wait for both threads to finish.
    t1.join();
    t2.join();

    return 0;
}


/*

Difference Between lock_guard and unique_lock
lock_guard:
-------------
- Very simple and lightweight.
- Locks the mutex immediately when created.
- Unlocks automatically when it goes out of scope.
- You cannot manually unlock or relock it.
- Best choice for simple scoped locking.

Think of it like:
“I just need basic protection. Nothing fancy.”


unique_lock:
--------------
- More powerful and flexible.
- Can delay locking (std::defer_lock).
- Can manually lock() and unlock().
- Supports try_lock().
- Supports timed locking.
- Can be moved (move semantics).
- Slightly heavier than lock_guard.

Think of it like:
“I might need more control over when and how I lock.”

Simple rule:
Use lock_guard when you just need basic locking.

Use unique_lock when you need extra control.

*/



/*
BOTTOM LINE:
unique_lock is used mostly when u want to lock a mutex 
unique_lock is used when you need more flexibility, like deferred locking,
timed locking, or manual unlocks inside the scope.”
Where as lock guard is used :
lock_guard is preferred because it’s lightweight, locks a mutex for a scope, and unlocks automatically.

IN SIMPLE WORDS:
lock_guard → “I just need to lock & unlock automatically, nothing fancy”

unique_lock → “I may want to lock, unlock, move, defer, or try/timed lock”
*/
