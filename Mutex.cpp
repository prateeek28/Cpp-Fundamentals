
  //********************************MUTEX IN CPP******************************/
//mutex in cpp? | why to use mutex? | what is race conmdition how to solve it?
// what is critical section.
// MUTEX : mutual exculusion(samjhota).
//RACE CONDITION :
//1.It is a situation where two or more thread / process happens to change OR modifiy a common data at a time.
//2.If there is a race condition then we have to protect it and that thing i called critical section/region.
//MUTEX:
//1.Mutex is used to avoid race condition
//2.we use lock() and unlock() to avoid race condition.

#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int Myammount= 0;
mutex m;
void addmoney(){
    m.lock();
    ++Myammount; // critical region, race condition
    m.unlock();
};
int main(){
    thread t1(addmoney);
    thread t2(addmoney);
    thread t3(addmoney);  
    //here whats happning whenever a thread goes to cpu whichever 
    //reaches first will access the mutext lock first and till that time
    //the other threads will be waiting for that thread to finish its work.
    thread t4(addmoney);
    thread t5(addmoney);
    thread t6(addmoney);
    t1.join();
    t2.join();
    t3.join();
    t4.join();
    t5.join();
    t6.join();
    cout<<"Myammount = "<<Myammount<<endl;
    return 0;
}

