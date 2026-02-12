/**
 * @file raii_example.cpp
 * @brief Demonstrates RAII (Resource Acquisition Is Initialization) in C++.
 *
 * RAII means:
 * - Resource is acquired inside constructor.
 * - Resource is released inside destructor.
 *
 * This ensures:
 * ✔ Automatic cleanup
 * ✔ No memory leaks
 * ✔ Exception safety
 */

#include <iostream>
using namespace std;

bool something_bad() {
    return true;
}

class IntWrapper {
private:
    int* p; 

public:
    IntWrapper(int value) {
        p = new int(value);
        cout << "Memory allocated. Value = " << *p << endl;
    }

    ~IntWrapper() {
        cout << "Destructor called. Releasing memory for value = " << *p << endl;
        delete p;
        cout << "Memory released." << endl;
    }
};

void func() {

    IntWrapper obj(10);

    cout << "Something bad happened. Returning early..." << endl;

    if (something_bad())
        return;  // Destructor will still execute here
}

int main() {

    func();

    cout << "Back in main." << endl;

    return 0;
}

/*
----------------------------------------
WHY THIS IS RAII?
----------------------------------------

1. Resource (memory) is acquired in constructor.
2. Resource is released in destructor.
3. Destructor runs automatically when object
   goes out of scope.

Even if:
- Function returns early
- Exception is thrown

Memory will still be cleaned safely.

----------------------------------------
REAL-WORLD EXAMPLES OF RAII
----------------------------------------

- std::lock_guard (mutex management)
- std::unique_ptr (smart pointers)
- File streams (file handling)

RAII is one of the most important
C++ design principles.
*/
