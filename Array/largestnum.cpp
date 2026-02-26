// Find Largest Element in Array
// Input: 1 4 2 9 5
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 5 ,8, 9,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    int largest = arr[0];
    
    for (int i = 0; i < length; i++){
        if(arr[i] > largest)
        largest = arr[i];
    }
    cout<<largest<<endl;
    return 0;
}