// count frequency of char problems- AABBBCDDEEFFGHHHI
 
 #include <iostream>
 using namespace std;
 
 int main(){
     char arr[] = "AABBBCDDEEFFGHHHI";
     int length = sizeof(arr)/sizeof(arr[0]);
     int freq[256] = {0};
     for(int i =0 ; i<length; i++){
         freq[arr[i]]++;
     }
     for (int i =0; i<length ; i++){
         if(freq[arr[i]] != 0){
             cout<<arr[i]<<" : "<< freq[arr[i]]<<endl;
             freq[arr[i]]=0;
         }
     }
     return 0;
 }