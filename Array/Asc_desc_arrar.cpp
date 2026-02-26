//Sorting array in ascending and decending order
#include <iostream>
using namespace std;

int main() {
    int arr[] = {5, 2, 9, 1, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    // Ascending sort
    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            //if(arr[i]<arr[j]) for decending order
            if(arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    cout << "Ascending Order: ";
    for(int i = 0; i < n; i++)
        cout << arr[i] << " ";
    return 0;
}
