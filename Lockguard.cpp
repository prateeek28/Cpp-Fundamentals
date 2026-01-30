/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
/*LOCK GUARD IN CPP. SYNTAX-> (std::lock_guard<mutex> lock(m1))
// NOTES
// 1. it is very lightweight wrapper for owing mutex on scoped basis.
// 2. it aquires mutex lock the moment u create the obj of lock_guard
// 3.it automatically removes the lock when it goes out of scope.
//4 . you cannot explicitly unclock the lock_guard.
//5. you cannot copy lock guard.*/
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;
std:: mutex m1;
int buffer = 0;
void task(const char * threadnum, int loopfor){
    std::lock_guard<mutex> lock(m1); //as the obj is created it aquires mutex lock and released when goes out of scope
    for(int i = 0; i<loopfor; ++i){
        buffer ++; // critical region
        cout<<threadnum<<" "<<buffer<<endl;
    }
}// unlocks here when it goes out of scope
int main(){
    thread t1(task ,"t1", 10);
    thread t2 (task,"t2", 10);
    t1.join();
    t2.join();
    return 0;
}
