/**
 * @file UniqueLockExample.cpp
 * @brief Demonstrates usage of std::unique_lock with std::mutex in multithreading.
 *
 * This program shows:
 * - How to protect shared resources using mutex.
 * - How to use std::unique_lock with deferred locking.
 * - Difference between automatic and manual locking.
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/**
 * @brief Global mutex to protect shared resource.
 */
std::mutex m1;

/**
 * @brief Shared resource accessed by multiple threads.
 */
int buffer = 0;


/**
 * @brief Thread task function.
 *
 * Demonstrates deferred locking using std::unique_lock.
 *
 * @param threadnumber Identifier of the thread.
 * @param loopfor Number of times to increment buffer.
 */
void task(const char* threadnumber, int loopfor) {

    /**
     * @brief Create unique_lock with deferred locking.
     *
     * std::defer_lock means:
     * - Mutex is NOT locked immediately.
     * - We must call lock() manually.
     */
    std::unique_lock<std::mutex> lock(m1, std::defer_lock);

    // ---- Code here runs WITHOUT lock ----
    // You can place non-critical section code here

    /**
     * @brief Manually locking the mutex.
     */
    lock.lock();

    /**
     * @brief Critical section.
     * Only one thread can execute this part at a time.
     */
    for (int i = 0; i < loopfor; ++i) {
        buffer++;
        std::cout << threadnumber << " " << buffer << std::endl;
    }

    /**
     * @note No need to call lock.unlock().
     * Destructor of unique_lock automatically unlocks the mutex.
     */
}


/**
 * @brief Entry point of the program.
 *
 * Creates two threads that modify shared buffer.
 * Mutex ensures safe access to shared resource.
 */
int main() {

    /**
     * @brief Creating threads.
     */
    std::thread t1(task, "t1", 5);
    std::thread t2(task, "t2", 5);

    /**
     * @brief Waiting for threads to complete.
     */
    t1.join();
    t2.join();

    return 0;
}


/**
 * @section LockGuardVsUniqueLock Difference Between lock_guard and unique_lock
 *
 * @subsection lock_guard
 * - Lightweight
 * - Locks immediately
 * - Unlocks automatically at end of scope
 * - Cannot manually unlock/relock
 *
 * @subsection unique_lock
 * - More flexible
 * - Supports:
 *      - Deferred locking (std::defer_lock)
 *      - Manual lock/unlock
 *      - try_lock()
 *      - timed locking
 *      - Move semantics
 *
 * @note Use lock_guard when simple scoped locking is needed.
 * @note Use unique_lock when advanced locking control is required.
 *
 * @warning Always protect shared data with a mutex
 *          to prevent race conditions.
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
