/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
/*
TOPIC: Condition Variable In C++ Threading
IMPORTANT POINT: CV are used for two purpose

A. Notify other threads
 B. Waiting for some conditions

1. Condition Variable allows running threads to wait on some conditions and once those conditions are met the waiting thread
is notified using:
a. notify one();
b. notify all();

2. You need mutex to use condition variable.

3. If some thread want to wait on some condition then it has to do these things:
a. Acquire the mutex lock using std::unique_lock<std::mutex> lock(m);.
b. Execute wait, wait for, or wait_until. The wait operations atomically release the mutex
and suspend the execution of the thread.
c. When the condition variable is notified, the thread is awakened, and the mutex is atomically reacquired.
The thread should then check the condition and resume waiting if the wake up was spurious.
 // NOTE:
 // 1. Condition variables are used to synchronize two or more threads.
2. Best use case of condition variable is Producer/Consumer problem..
*/
#include<iostream>
#include<thread>
#include<mutex>
#include<condition_variable>
using namespace std;
std::condition_variable cv;
std::mutex m;
int balance=0;

void addmoney(int money){
    std::lock_guard<mutex> lg(m);
    balance = balance + money;
    cout<<"Amount added current balance "<<balance<<endl;
    cv.notify_one();
}
void withdrawmoney(int money){
    std::unique_lock<mutex> ul(m);
    cv.wait(ul, [] {return (balance !=0)? true : false; });
    if(balance>=money){
        balance= balance-money;
        cout<<"Ammount deducted"<<money<<std::endl;
    }else{
        cout<<"Ammount cant be deducted Current balance is less than "<<money<<std::endl;
        std::cout<<"Current balance is"<<balance<<std::endl;
    }
    }
    

int main(){
    thread t1(withdrawmoney, 500);
    std:this_thread::sleep_for(std::chrono::seconds(2));
    thread t2(addmoney , 1000);
    t1.join();
    t2.join();
    return 0;
    
}









