
/*
   TOPIC: STD::SET
    std::set is a container that:
    -> Stores UNIQUE elements only
    -> Automatically keeps elements sorted
    -> Is usually implemented using a Red-Black Tree
    So you don’t sort it.
    It always stays sorted by default.
*/

#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    set<int> s;

    /*
        Inserting elements
        insert() -> adds element
        If element already exists -> nothing happens
    */
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10);  // duplicate (will be ignored)

    //Here output will be always Sorted
    cout << "Elements in set: ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    //Size and empty
    cout << "Size: " << s.size() << endl;
    cout << "Is empty? " << s.empty() << endl;

    /*
        Finding elements
        find() -> returns iterator
        If not found -> returns s.end()
    */
    if (s.find(10) != s.end())
        cout << "10 found in set\n";

    /*
        count()
        Since set stores unique values,
        count() will return either 0 or 1
    */
    cout << "Count of 5: " << s.count(5) << endl;

    /*
        Removing elements
        erase(value) → removes that value
    */
    s.erase(5);

    cout << "After erase(5): ";
    for (int x : s)
        cout << x << " ";
    cout << endl;

    /*
        Lower and Upper Bound

        lower_bound(x) → first element >= x
        upper_bound(x) → first element > x
    */
    auto it1 = s.lower_bound(10);
    auto it2 = s.upper_bound(10);

    if (it1 != s.end())
        cout << "Lower bound of 10: " << *it1 << endl;

    if (it2 != s.end())
        cout << "Upper bound of 10: " << *it2 << endl;

    return 0;
}

 /*
        BOTTOM LINES:
        1) set stores UNIQUE elements only.
        2) Elements are always sorted.
        3) Internally uses a balanced tree (not contiguous memory).
        4) Insertion, deletion, search O(log n)
        5) You cannot modify elements directly (they are const).
        6) set = sorted + unique + fast search (log n).
    */