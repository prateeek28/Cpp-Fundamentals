
/*
TOPIC:
DEADLOCK-->
A deadlock happens when two or more threads are permanently blocked,
each waiting for a resource held by the other.
No thread can move forward.
Program appears “stuck”.
*/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

mutex m1, m2;

void task1() {
    m1.lock();
    cout << "Task1 locked m1\n";

    this_thread::sleep_for(chrono::milliseconds(100));

    m2.lock();   // waiting for m2
    cout << "Task1 locked m2\n";

    m2.unlock();
    m1.unlock();
}

void task2() {
    m2.lock();
    cout << "Task2 locked m2\n";

    this_thread::sleep_for(chrono::milliseconds(100));

    m1.lock();   // waiting for m1
    cout << "Task2 locked m1\n";

    m1.unlock();
    m2.unlock();
}

int main() {
    thread t1(task1);
    thread t2(task2);

    t1.join();
    t2.join();
}
