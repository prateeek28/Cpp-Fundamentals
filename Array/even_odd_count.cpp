//Count Even and Odd Numbers
#include <iostream>
using namespace std;

int main() {
    int arr[] = {2, 4, 5 ,8, 9,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    int even = 0;
    int odd = 0;
    
    for (int i = 0; i < length; i++){
        if(i % 2 == 0)
        {
            even++;
        }
        else if(i%2 != 0)
        {
            odd++;
        }
    }
    cout<<" even count = "<<even<<endl;
    cout<<" odd count = "<<odd<<endl;
    return 0;
}