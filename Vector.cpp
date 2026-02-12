/*
    TOPIC: VECTOR
    What is std::vector?
    Think of vector as a dynamic array.
    It works like a normal array but can grow
    and shrink automatically.
    You don’t manage memory.
    It handles everything for you.
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    // Creating an empty vector of integers
    vector<int> vec;

    /*
        Adding elements
        1.push_back() -> adds element at the end
        2.emplace_back() -> constructs element directly (slightly faster for objects)
    */
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.emplace_back(40);

    /*
        Accessing elements
        []   -> fast but no safety check
        at() -> safe, throws error if index is wrong
    */
    cout << "First element using []: " << vec[0] << endl;
    cout << "Second element using at(): " << vec.at(1) << endl;

    cout << "Front(): " << vec.front() << endl; // first element
    cout << "Back(): " << vec.back() << endl;   // last element

    /*
        Size vs Capacity
        size()     -> how many elements are inside
        capacity() -> how much memory is allocated
        Capacity can be bigger than size.
    */
    cout << "Size: " << vec.size() << endl;
    cout << "Capacity: " << vec.capacity() << endl;

    /*
        reserve(n)
        -> tells vector to allocate memory in advance
        -> helps avoid multiple reallocations which helps performance boost
    */
    vec.reserve(10);

    /*
        resize(n)
        -> changes the number of elements
        -> if bigger, default values are added
        -> if smaller, elements are removed
    */
    vec.resize(6);

    /*
        Removing elements
    */
    vec.pop_back();              // removes last element
    vec.insert(vec.begin(), 5);  // inserts at beginning
    vec.erase(vec.begin());      // removes first element

    /*
        Let's refill vector for algorithm demo
    */
    vec = {5, 2, 8, 1, 9};

    /*
        Since vector stores data in contiguous memory,
        it works perfectly with STL algorithms.
    */

    sort(vec.begin(), vec.end());     // sort in ascending order
    reverse(vec.begin(), vec.end());  // reverse order

    int sum = accumulate(vec.begin(), vec.end(), 0); // sum of elements

    cout << "\nAfter sorting and reversing: ";
    for (int x : vec)
        cout << x << " ";

    cout << "\nSum: " << sum << endl;

    return 0;
}

    /*
        BOTTOM LINES
        1) vector grows automatically.
        2) When it grows, it may reallocate memory.
        3) Reallocation invalidates pointers and iterators.
        4) Use reserve() if you know size in advance.
        5) Use emplace_back() for complex objects.
        6) vector = flexible, safe, and powerful dynamic array.
    */