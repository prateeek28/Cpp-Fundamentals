/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
//Rule of 5.
#include <stdio.h>
#include<iostream>
#include <cstring>
using namespace std;
class Employee{
    private:
    char * name;
    double balance;
    public:
    Employee(){
        name = new char[1];
        name[0]='\0';
        balance = 0;
    }
    Employee(const char* n, double bal){
        name = new char[strlen(n)+1];
        strcpy(name, n);
        balance = bal;
    }
    Employee(const Employee &other){
        name = new char[strlen(other.name)+1];
        strcpy(name, other.name);
        balance = other.balance;
    }
    Employee& operator=(const Employee &other){
        if(this != &other){
          delete[]name;
          name = nullptr;
          name = new char[strlen(other.name)+1];
          strcpy(name, other.name);
          balance = other.balance;
          } return *this;
    }
    Employee (Employee&& other){
        name = other.name;
        balance = other.balance;
        other.name = nullptr;
        other.balance = NULL;
    }
    Employee& operator=(Employee&& other){
    if(this!= &other){
        delete[]name;
        name = other.name;
        other.name = nullptr;
        balance = other.balance;
        other.balance = NULL;
    }return *this;
    }
    void display(){
        cout<<(name ? name : "NULL")<<" "<<balance<<endl;
    }
    ~Employee(){
        delete[]name;
    }
};
int main()
{
    Employee e1("Prateek",900);
    Employee e2, e3, e4, e5;
    e2=e1;
    e3=std::move(e2);
    e4=e3;
    e5=std::move(e4);
    e1.display();
    e2.display();
    e3.display();
    e4.display();
    e5.display();

}