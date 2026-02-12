
/**
 * @file mutex_example.cpp
 * @brief Demonstrates the use of std::mutex to prevent race conditions.
 *
 * Concepts covered:
 * - What is a race condition?
 * - What is a critical section?
 * - Why mutex is needed?
 *
 * Mutex stands for "Mutual Exclusion".
 * It ensures that only one thread accesses
 * a shared resource at a time.
 */

#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

/// Shared resource
int MyAmount = 0;

/// Mutex to protect shared resource
std::mutex m;

void addmoney() {

    /**
     * Lock the mutex before entering
     * the critical section.
     */
    m.lock();

    ++MyAmount;  // Critical Section (shared resource modification)

    /**
     * Unlock after finishing work.
     */
    m.unlock();
}

int main() {

    thread t1(addmoney);
    thread t2(addmoney);
    thread t3(addmoney);
    thread t4(addmoney);
    thread t5(addmoney);
    thread t6(addmoney);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();

    cout << "MyAmount = " << MyAmount << endl;

    return 0;
}

/*
----------------------------------------
IMPORTANT CONCEPTS
----------------------------------------

1. Race Condition:
   When multiple threads try to modify
   the same data at the same time,
   leading to unpredictable results.

2. Critical Section:
   The part of code where shared data
   is accessed or modified.

3. Mutex:
   Prevents race condition by allowing
   only one thread at a time to execute
   the critical section.
