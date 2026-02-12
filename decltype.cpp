/*
@File decltype.cpp
What is decltype?
->decltype is used to get the type of an expression at compile time.
 It does NOT evaluate the expression.
 It only inspects the type.
*/
#include <iostream>
using namespace std;
int main() {

    int a = 10;

    // decltype(a) means: "type of a"
    decltype(a) b = 20;  

    std::cout << y << std::endl;

    return 0;
}
/*
BOTTOM LINE:
Explanation:
a is int
decltype(a) becomes int
So b is also int
*/


/*
EXAMPLE 2:-
decltype with Functions
*/
#include <iostream>

// Function returning double
double multiply(int a, double b) {
    return a * b;
}

int main() {

    // Get return type of function
    decltype(multiply(2, 3.5)) result = 10.5;

    std::cout << result << std::endl;

    return 0;
}
/*
BOTTOM LINE:
decltype(multiply(...)) becomes double.
*/



/*
EXAMPLE 3 :
Reference Behavior of auto and decltype
*/

#include <iostream>

int main() {

    int x = 10;
    int& ref = x;

    auto a = ref;        // int (reference removed)
    decltype(ref) b = x; // int& (reference preserved)

    a = 20;
    b = 30;

    std::cout << x << std::endl; //op-30

    return 0;
}

/*
BOTTOM LINE:
Why?
auto a = ref; → a becomes int (copy)
decltype(ref) b = x; → b becomes int&
So modifying b changes x
-> decltype keeps exact type
-> auto may drop reference
*/