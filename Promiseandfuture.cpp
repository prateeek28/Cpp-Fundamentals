/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
Topic: FUTURE AND PROMISE
--> They are used for one-time communication between threads.

👉 One thread produces a value
👉 Another thread consumes the value

Think of it like this:

promise = “I will give you a value later”
future = “I’ll wait and receive that value”

Q. Why do we need them?

Because:

Threads don’t return values directly

Global variables are unsafe

Condition variables are complex

✔ future & promise solve this cleanly

Basic Flow (IMPORTANT)
Thread A → promise.set_value()
             ↓
Thread B → future.get()


promise sets the result

future gets the result

*/
#include <iostream>
#include <thread>
#include <future>
using namespace std;

void add(promise<int> p) {
    p.set_value(10 + 20);
}

int main() {
    promise<int> p;
    future<int> f = p.get_future();

    thread t(add, move(p));

    cout << "Result: " << f.get() << endl;

    t.join();
}
