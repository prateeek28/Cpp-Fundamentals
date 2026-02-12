
/**
 * condition_variable_example.cpp
 * Demonstrates how to use std::condition_variable in C++ threading.
 *
 * This example shows:
 * - How one thread waits for a condition.
 * - How another thread notifies it.
 * - Proper use of mutex and condition_variable.
 *
 * Best real-world example: Producer / Consumer pattern.
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <chrono>

using namespace std;

/// Global condition variable used for thread synchronization
std::condition_variable cv;

/// Mutex to protect shared data (balance)
std::mutex m;

/// Shared resource
int balance = 0;

/**
 * @brief Adds money to the shared balance.
 *
 * This function:
 * - Locks the mutex
 * - Updates balance
 * - Notifies one waiting thread
 *
 * @param money Amount to add
 */
void addmoney(int money) {
    std::lock_guard<std::mutex> lg(m);  // Lock automatically released at end of scope

    balance += money;
    cout << "Amount added. Current balance: " << balance << endl;

    cv.notify_one();  // Wake up one waiting thread
}

/**
 * Withdraws money from the shared balance.
 *
 * This function:
 * - Waits until balance is not zero
 * - Checks if enough money is available
 * - Deducts if possible
 *
 * @param money Amount to withdraw
 */
void withdrawmoney(int money) {

    std::unique_lock<std::mutex> ul(m);

    /**
     * Wait until balance becomes greater than 0.
     *
     * wait():
     * - Releases the mutex
     * - Puts thread to sleep
     * - Reacquires mutex automatically when notified
     */
    cv.wait(ul, [] { return balance != 0; });

    if (balance >= money) {
        balance -= money;
        cout << "Amount deducted: " << money << endl;
    } else {
        cout << "Cannot deduct. Balance is less than " << money << endl;
        cout << "Current balance: " << balance << endl;
    }
}

int main() {

    thread t1(withdrawmoney, 500);

    // Give withdraw thread time to start waiting
    std::this_thread::sleep_for(std::chrono::seconds(2));

    thread t2(addmoney, 1000);

    t1.join();
    t2.join();

    return 0;
}




//Bottom line
/*
A. Notify other threads
B. Waiting for some conditions
1. Condition Variable allows running threads to wait on some conditions 
and once those conditions are met the waiting thread is notified using:
a. notify one();
b. notify all();
2. You need mutex to use condition variable.
3. If some thread want to wait on some condition then it has to do these things:
a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);.
b. Execute wait, wait for, or wait_until. The wait operations atomically release the mutex
and suspend the execution of the thread.
c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.
The thread should then check the condition and resume waiting if the wake up was spurious.
NOTE:
1. Condition variables are used to synchronize two or more threads.
*/