/**
 * @file placement_new_example.cpp
 * @brief Example showing normal new/delete vs placement new in C++.
 *
 * This program demonstrates:
 * - How objects are normally created using new and deleted using delete.
 * - How placement new works (constructing objects in pre-allocated memory).
 * - Why destructors must be called manually when using placement new.
 */

#include <iostream>
#include <new>   // Required for placement new

using namespace std;


class base {
    int a;  

public:
    base() {
        cout << "Constructor called" << endl;
    }
    ~base() {
        cout << "Destructor called" << endl;
    }
};
int main() {

    cout << "Normal way:" << endl;

    /**
     * Normal allocation:
     * - Memory is allocated on the heap.
     * - Constructor is automatically called.
     */
    base* obj = new base();

    /**
     * delete:
     * - Destructor is automatically called.
     * - Memory is freed.
     */
    delete obj;


    cout << "\nPlacement new way:" << endl;

    /**
     * Step 1:
     * Allocate raw memory manually.
     * No constructor is called here.
     */
    char* memory = new char[10 * sizeof(base)];

    /**
     * Step 2:
     * Use placement new to construct objects
     * inside the already allocated memory.
     *
     * This only calls the constructor.
     * It does NOT allocate memory again.
     */
    base* obj1 = new (memory + 0 * sizeof(base)) base();
    base* obj2 = new (memory + 1 * sizeof(base)) base();
    base* obj3 = new (memory + 2 * sizeof(base)) base();
    base* obj4 = new (memory + 3 * sizeof(base)) base();

    /**
     * Important:
     * When using placement new, destructors
     * are NOT called automatically.
     *
     * We must call them manually.
     */
    obj1->~base();
    obj2->~base();
    obj3->~base();
    obj4->~base();

    /**
     * Finally, free the raw memory block.
     */
    delete[] memory;

    return 0;
}
