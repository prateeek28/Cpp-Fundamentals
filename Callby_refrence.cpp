/*
@file callby_refrence.cpp
@brief this file demonstrates how to use reference in multiple situations.
*/

#include <stdio.h>
#include <iostream>
using namespace std;

/*
Q1.Write a C++ program to swap two numbers using call by reference.

void swap(int &a, int &b)
{
  //swapping logic without using third var
    a=a+b;
    b=a-b;
    a=a-b;
}
int main()
{
    int x=10;
    int y=20;
    swap(x,y);
    cout<<x<<" "<<y<<endl;
    return 0;
}
*/

/*
Q2.Create a function that takes a reference to an integer and doubles its value. 

int fun(int &x ){
    x = 2*x;
    return x;
}
int main(){
    int a = 10;
    fun(a);
    cout<<a<<endl;
    return 0;
}
*/


/*
Q3.Implement a function that returns the larger of two integers using references. 

int large(int &x, int &y){
    if(x>y){
        return x;
    }else{
        return y;
    }
}
int main(){
    int a=20; b = 60;
    int res = large(a,b);
    cout<<res<<endl;
    return 0;
}
*/


/*Q4.Write a program to demonstrate constant references in function parameters. 

int sum (const int &a, const int &b){
    //a=10;
    return a+b;
}
int main(){
    int x = 10;
    int y= 10;
    
    int res = sum(x,y);
    cout<<res<<endl;
}
*/

/*
//Q5.Write a program to change the value of an array element using reference to array elements. 

int main(){
    int arr[20]={1,2,3,4,5,6,7,8,9,10};
    int &y = arr[2];
    y = 20;
    int &x = arr[15];
    x = 15;
    
    for(int i= 0; i<=20; i++){
        cout<<arr[i]<<endl;
    }
}
*/

