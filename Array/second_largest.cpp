//Find Second Largest Element

using namespace std;
#include <cstring>
#include <iostream>

int main() {
 int arr[]= {21,32,43,54,66,71,90};
 int len = sizeof(arr)/ sizeof (arr[0]);
 int largest = 0 ;
 int seclargest = 0 ;
 //Logic for Second largest element
 for (int i = 0; i<len ; i++){
     if(arr[i]>largest){
         seclargest = largest;
         largest = arr[i];
     }else if(arr[i] > seclargest && arr[i] != largest){
         seclargest = arr[i];
     }
 }
 
 cout<<seclargest;
 return 0;
}