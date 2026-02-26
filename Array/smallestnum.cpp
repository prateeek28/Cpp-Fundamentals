// Find smallest Element in Array
// Input: 1 4 2 9 5
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 5 ,8, 9,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    int smallest = arr[0];
    
    for (int i = 0; i < length; i++){
        if(arr[i] < smallest)
        smallest = arr[i];
    }
    cout<<"Smallest num = "<<smallest<<endl;
    return 0;
}