//Find Sum of All Elements
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 5 ,8, 9,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    int sum = 0;
    
    for (int i = 0; i < length; i++){
        sum = sum+arr[i];
    }
    cout<<"Sum = "<<sum<<endl;
    return 0;
}