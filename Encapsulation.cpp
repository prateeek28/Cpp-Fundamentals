/*
Encapsulation Program:
Encapsulation means binding data and functions together and hiding data using access specifiers.
*/
#include<iostream>
using namespace std;
class Bank {
private:
    int balance; //data variables hidden

public:
    void setBalance(int b) { //function method to set the private data
        balance = b;
    }
    int getBalance() { //getting it through get method
        return balance;
    }
};
int main(){
    Bank b1;
    b1.setBalance(500000);
    cout<<b1.getBalance()<<endl;
}
