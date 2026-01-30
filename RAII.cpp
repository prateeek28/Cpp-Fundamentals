/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
using namespace  std;
bool something_bad(){
    return true;
}
class intwrapper{
    private:
    int *p;
    public:
    intwrapper(int value){
        cout<<"memory allocated for p"<<*p<<endl;
        p = new int(value);
         
    }
    ~intwrapper(){
        cout<<"destructor called "<<*p<<endl;
        
        delete p;
         cout<<"memory released for p"<<*p<<endl;
         
    }
};

void func()
{
    intwrapper obj(10);
    cout<<"something bad has happned i m returning......."<<endl;
    if(something_bad())
    return ;
}

int main(){
    func();
    cout<<"back in main"<<endl;
    return 0;
}
