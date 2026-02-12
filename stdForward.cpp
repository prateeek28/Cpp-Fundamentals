/*
FILE std::forward
Purpose: Used in template code to implement perfect forwarding.
Problem it solves: In templates, you may not know if an argument is lvalue or rvalue. 
Using std::forward preserves the value category when passing it to another function
*/
#include <utility>
#include <iostream>

void process(int& x) 
{ std::cout << "Lvalue\n"; }
void process(int&& x)
{ std::cout << "Rvalue\n"; }

template <typename T>
void wrapper(T&& arg) {
  /*
   // process(arg); // arg is always treated as lvalue here
  Why?
  Because inside wrapper, arg has a name → and anything with a name is an lvalue,
  even if it originally was rvalue.
  */
    process(std::forward<T>(arg)); // Preserves lvalue/rvalue type.. perfect forwarding
}

int main() {
    int a = 10;
    wrapper(a);          // Lvalue -> calls process(int&)
    wrapper(20);         // Rvalue -> calls process(int&&)
}

/*
BOTTOM LINE:-
What actually std::forward does?
It conditionally casts:
If original argument was lvalue → forward as lvalue
If original argument was rvalue → forward as rvalue
*/