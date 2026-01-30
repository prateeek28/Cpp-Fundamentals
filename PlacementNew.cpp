/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <cstring>
using namespace std;
//new placement useage in cpp
class base{
    int a;
    public:
    base(){
        cout<<" i am constructor "<<endl;
    }
    ~base(){
        cout<<" i m destructor "<<endl;
    }
};
int main(){
    cout<<"the normal way"<<endl;
    base *obj= new base();
    delete obj;
    cout<<"the new placement way"<<endl; 
    char * memory = new char [10*sizeof(base)];
    
    base *obj1 = new (memory+0 * sizeof(base)) base();
    base *obj2 = new (memory+1 * sizeof(base)) base();
    base *obj3 = new (memory+2 * sizeof(base)) base();
    base *obj4 = new (memory+3 * sizeof(base)) base();
    
    obj1-> ~base();
    obj2-> ~base();
    obj3-> ~base();
    obj4-> ~base();
    return 0;
    
}