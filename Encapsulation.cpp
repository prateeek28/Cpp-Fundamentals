/**
 * @file encapsulation_example.cpp
 * Encapsulation means:
 * - Binding data and functions together inside a class.
 * - Restricting direct access to data using access specifiers.
 *
 * In this example:
 * - The balance variable is private.
 * - It can only be accessed through public methods.
 */

#include <iostream>
using namespace std;

class Bank {
private:
    int balance;  ///< Private data member (hidden from outside access)

public:

    void setBalance(int b) {
        balance = b;
    }

    int getBalance() {
        return balance;
    }
};

int main() {

    Bank b1;

    // Setting balance using public method
    b1.setBalance(500000);

    // Getting balance using public method
    cout << b1.getBalance() << endl;

    return 0;
}

/*
----------------------------------------
WHY THIS IS ENCAPSULATION?
----------------------------------------

1. balance is private → cannot access directly like:
      b1.balance = 1000;  (This would cause error)

2. Data is accessed only through methods.

3. This allows:
   - Data protection
   - Validation (if needed)
   - Better control over internal state

Real-world example:
ATM machine does not give you direct access
to bank database. You use functions like
withdraw, deposit, check balance.
*/
