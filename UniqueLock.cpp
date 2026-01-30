/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
unique_lock is used mostly when u want to lock a mutex 
unique_lock is used when you need more flexibility, like deferred locking,
timed locking, or manual unlocks inside the scope.”
Where as lock guard is used :
lock_guard is preferred because it’s lightweight, locks a mutex for a scope, and unlocks automatically.

IN SIMPLE WORDS:
lock_guard → “I just need to lock & unlock automatically, nothing fancy”

unique_lock → “I may want to lock, unlock, move, defer, or try/timed lock”
*/

#include <iostream>
#include<iostream>
#include <thread>
#include <mutex>
using namespace std;
std::mutex m1;
int buffer=0;
/* EXAMPLE 1
void task(const char * threadnumber, int loopfor){
    std::unique_lock<std::mutex> lock(m1);
    for(int i = 0; i<loopfor; ++i){
        buffer++;
        std::cout << threadnumber<<" "<<buffer<< std::endl;
    }
}
 */
 // EXample t
 void task(const char* threadnumber, int loopfor){
     std::unique_lock<std::mutex> lock(m1, std::defer_lock); // does npot call lock on mutex m1, because it is using defer_lock lock
     
     // here in middle i can have n number of code without any lock and after that i can lock it
     lock.lock(); // here i have locked it by explicitly saying it manullay to lock the mutex m1.
     for(int i=0; i<loopfor; ++i){
         buffer++;
         std::cout<<threadnumber<<" "<<buffer<<std::endl;
     }
     //lock.unlock is not needed because we are using unique_lock i handelles it automatically as it will be unlock by the destructor of unique lock.
 } 
 int main(){
    std::thread t1(task, " t1", 5);
    std::thread t2 (task, " t2", 5);
    t1.join();
    t2.join();
    return 0;
}