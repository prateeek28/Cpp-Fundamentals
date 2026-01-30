/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <iostream>
#include <thread>
using namespace std;
//program to use functor in thread 
class base{
    public:
    void operator()(int x){
        while (x-- > 0)
        cout<<x<<endl;
    }
};
int main(){
  std:: thread t((base()
  ),10);  

    t.join();
    return 0;
}