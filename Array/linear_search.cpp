//Search an Element in Array (Linear Search)
#include <iostream> 
using namespace std;

int main() {
 int arr[]= {21,32,43,54,99,71,90};
 int length = sizeof(arr)/ sizeof(arr[0]);
 int i;
 int key = 54;
 for(i = 0; i<length ; i++){
     if(arr[i] == key ){
         cout<<"fount the element on index = "<<i<<endl;
     return 0 ;
     } 
 }
 cout<< "not found" <<endl;
 return 0;
}