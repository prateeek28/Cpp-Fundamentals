/*
    @file std::array

    What is std::array ?
    std::array is a fixed-size container introduced in C++11.
    It is a wrapper around normal C-style arrays.
    It stores elements:
        - In contiguous memory
        - With fixed size (cannot grow or shrink)

    Why to use std::array ?
    1. Safer than C-style arrays
    2. Knows its own size (.size())
    3. Works with STL algorithms
    4. Supports iterators
    5. Can be copied and assigned
*/
#include <iostream>
#include <array>
#include <algorithm>   // sort, reverse, fill
#include <numeric>     // accumulate
using namespace std;
int main()
{
    // Declaration & Initialization
    array<int, 5> arr = {10, 20, 30, 40, 50};

    //ELEMENT ACCESS FUNCTIONS

    cout << "Using operator[]: " << arr[0] << endl;   // No bounds checking
    cout << "Using at(): " << arr.at(1) << endl;      // Safe (throws exception if out of range)
    cout << "Front(): " << arr.front() << endl;       // First element
    cout << "Back(): " << arr.back() << endl;         // Last element
    cout << "Data(): " << arr.data() << endl;         // Pointer to raw array memory

     //CAPACITY FUNCTIONS
 
    cout << "Size(): " << arr.size() << endl;         // Number of elements
    cout << "Max_size(): " << arr.max_size() << endl; // Same as size (fixed container)
    cout << "Empty(): " << arr.empty() << endl;       // True if size == 0

      //MODIFIER FUNCTIONS
   
    arr.fill(100);   // Fill entire array with 100

    cout << "\nAfter fill(): ";
    for (int x : arr)
        cout << x << " ";

    array<int, 5> arr2 = {1, 2, 3, 4, 5};

    arr.swap(arr2);  // Swap contents of two arrays

    cout << "\nAfter swap(): ";
    for (int x : arr)
        cout << x << " ";
    
      //  STL ALGORITHM SUPPORT

    sort(arr.begin(), arr.end());    // Sort elements
    reverse(arr.begin(), arr.end()); // Reverse elements

    int sum = accumulate(arr.begin(), arr.end(), 0); // Sum of elements

    cout << "\nAfter sort & reverse: ";
    for (int x : arr)
        cout << x << " ";

    cout << "\nSum using accumulate(): " << sum << endl;

    return 0;
}
  /*
        KEY DIFFERENCE VS C ARRAY
        int arr[5];  -> no .size(), no STL support
        std::array   -> has member functions + STL compatible
        NOTE:
        - Size must be known at compile time
        - Cannot resize like vector
    */