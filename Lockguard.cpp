
/**
 * @file lock_guard_example.cpp
 * @brief Demonstrates the use of std::lock_guard in C++ multithreading.
 *
 * std::lock_guard is a lightweight RAII wrapper
 * used to manage mutex locking automatically.
 *
 * Key points:
 * 1. Locks the mutex immediately when created.
 * 2. Automatically unlocks when it goes out of scope.
 * 3. Cannot be manually unlocked.
 * 4. Cannot be copied.
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/// Global mutex used to protect shared data
std::mutex m1;

/// Shared resource
int buffer = 0;

void task(const char* threadnum, int loopfor) {

    /**
     * lock_guard acquires the lock immediately.
     * The mutex will automatically unlock
     * when this function ends (scope ends).
     */
    std::lock_guard<std::mutex> lock(m1);

    for (int i = 0; i < loopfor; ++i) {
        buffer++;  // Critical section
        cout << threadnum << " " << buffer << endl;
    }

} // Mutex automatically unlocked here

int main() {

    thread t1(task, "t1", 10);
    thread t2(task, "t2", 10);

    t1.join();
    t2.join();

    return 0;
}

/*
----------------------------------------
WHY USE lock_guard?
----------------------------------------

Without mutex:
Multiple threads may modify buffer at the same time,
causing race condition and unpredictable output.

With lock_guard:
Only one thread enters the critical section at a time.

Important:
lock_guard follows RAII principle —
Resource Acquisition Is Initialization.

This makes code:
 Safer
 Cleaner
 Exception safe
 Easier to maintain
*/


