// Recursive sum of a natural number 
// Eg 5 
// 5+4+3+2+1
// Result : 15
#include<iostream>
using namespace std;
int sum(int x){
    if(x==1)
    return 1;
   return x + sum (x-1);
};
int main(){
    int n=5;
   cout<< sum(n);
  
}