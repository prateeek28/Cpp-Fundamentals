#include <iostream>
using namespace std;

template<typename T> 
class UniquePtr{
    private:
    T *ptr;
    
    public:
    
    //Parametarized constructor
    explicit UniquePtr(T*p = nullptr) : ptr(p) {}
    ~UniquePtr(){
        delete ptr;
    }
    //No Copy allowed.
    UniquePtr(const UniquePtr &) = delete;
    UniquePtr& operator=(const UniquePtr&) = delete;
    
    UniquePtr(UniquePtr && obj){
        ptr = obj.ptr;
        obj.ptr = nullptr;
    }
    
    UniquePtr& operator=(UniquePtr && obj){
        if(this != obj){
            delete ptr;
            ptr = obj.ptr;
            obj.ptr = nullptr;
        }
        return *this;
    }
    
    T&operator*(){return *ptr;}
    T* operator->(){return ptr;}
};

int main(){
    UniquePtr<int> p1(new int (10));
    
    cout<<*p1<<endl;
    
    UniquePtr<int> p2 = std::move(p1);
    
    cout<<*p2<<endl;
    
    return 0;
}