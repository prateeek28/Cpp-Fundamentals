//Reverse an Array
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 5 ,8, 9};
    int length = sizeof(arr)/sizeof(arr[0]);
    int start = 0; 
    int end = length - 1;
    while (start < end){
        int temp = arr [start];
        arr[start]= arr[end];
        arr[end] = temp;
        
        start ++;
        end --;
        
    }
    for (int i = 0; i < length; i++){
       cout<<" "<<arr[i];
        }
   
    return 0;
}