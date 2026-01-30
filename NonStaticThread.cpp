/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <thread>
using namespace std;
/*
//program using non static data members in thread
class base
{
    public:
    void run(int x){
        while (x-- > 0){
            cout<<x<<endl;
        }
    }
};

int main()
{
base b;
std:: thread t (&base::run, &b, 10);
t.join();
    return 0;
}
*/

// program for static one 
class base{
    public:
   static void run(int x){
        while(x -- > 0){
            cout<<x<<endl;
        }
    }
};
int main(){
    thread t(&base::run,10);
    t.join();
    return 0;
}
























