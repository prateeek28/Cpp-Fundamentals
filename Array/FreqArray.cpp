//Find Frequency of Each Element

#include <iostream> 
using namespace std;
int main() {
int arr[]= {1,2,2,3,4,5,5,3,1};
int length = sizeof(arr)/ sizeof(arr[0]);
//ASCII VALUE OF ALL ELEMENTS 256
int freq[256]= {0};
for (int i = 0; i< length ; i++){
// freq[arr[i]]++;
 int number = arr[i]; // take current number
 freq[number] = freq[number] + 1; // increase the count
}
for(int i = 0; i<256 ; i++)
if(freq[i] > 0)
cout << i << " -> " << freq[i] << endl;

return 0;
}