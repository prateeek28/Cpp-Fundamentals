//Topic : Thread safe singelton.
#include <iostream>
using namespace std;
class singelton{
    private:
    singelton(){
        cout<<"instance created "<<endl;
    }
    
    singelton (const singelton&)=delete;
    singelton& operator=(const singelton)=delete;
    public:
    //public static method to get single object
    static singelton& getInstance(){
       static singelton instance;
        return instance;
    }
    void show(){
        cout<<" Hello from singelton "<<endl;
    }
};

int main() {
  singelton& s1= singelton::getInstance();
  s1.show();
  singelton& s2= singelton::getInstance();
  s2.show();
  
  if(&s1 == &s2){
      cout<<"both belong to same obj"<<endl;
      
  }else{
      cout<<"diffrent";
  }
  
  
}