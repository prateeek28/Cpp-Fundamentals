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

/**
 * @brief Simulates an error condition.
 *
 * @return true Always returns true to simulate failure.
 */
bool something_bad() {
    return true;
}

/**
 * @class IntWrapper
 * @brief A simple RAII class managing dynamic memory.
 *
 * This class:
 * - Allocates memory in constructor.
 * - Releases memory in destructor.
 *
 * Even if function exits early,
 * destructor will automatically free memory.
 */
class IntWrapper {
private:
    int* p;  ///< Pointer to dynamically allocated integer

public:

    /**
     * @brief Constructor
     *
     * Allocates memory and initializes value.
     *
     * @param value Initial value to store.
     */
    IntWrapper(int value) {
        p = new int(value);
        cout << "Memory allocated. Value = " << *p << endl;
    }

    /**
     * @brief Destructor
     *
     * Releases allocated memory.
     */
    ~IntWrapper() {
        cout << "Destructor called. Releasing memory for value = " << *p << endl;
        delete p;
        cout << "Memory released." << endl;
    }
};

/**
 * @brief Function demonstrating early return.
 *
 * Even if function exits early,
 * destructor of local object is still called.
 */
void func() {

    IntWrapper obj(10);

    cout << "Something bad happened. Returning early..." << endl;

    if (something_bad())
        return;  // Destructor will still execute here
}

/**
 * @brief Entry point of program.
 */
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
