/**
 * @file rule_of_five_example.cpp
 * @brief Demonstrates the Rule of Five in C++.
 *
 * Rule of Five states that if a class manages a resource
 * (like dynamic memory), it should define:
 *
 * 1. Destructor
 * 2. Copy Constructor
 * 3. Copy Assignment Operator
 * 4. Move Constructor
 * 5. Move Assignment Operator
 *
 * This prevents memory leaks and ensures proper
 * deep copy and move behavior.
 */

#include <iostream>
#include <cstring>
using namespace std;
class Employee {
private:
    char* name;      ///< Dynamically allocated name
    double balance;  ///< Employee balance/salary

public:

    /**
      Default Constructor
     * Allocates empty string and initializes balance to 0.
     */
    Employee() {
        name = new char[1];
        name[0] = '\0';
        balance = 0;
    }

    /**
     *  Parameterized Constructor
     *  n Employee name
     *  bal Employee balance
     */
    Employee(const char* n, double bal) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
        balance = bal;
    }

    /**
     * Copy Constructor (Deep Copy)
     * Allocates new memory and copies data.
     */
    Employee(const Employee& other) {
        name = new char[strlen(other.name) + 1];
        strcpy(name, other.name);
        balance = other.balance;
    }

    /**
     * Copy Assignment Operator (Deep Copy)
     * Frees old memory and copies new data.
     */
    Employee& operator=(const Employee& other) {
        if (this != &other) {
            delete[] name;

            name = new char[strlen(other.name) + 1];
            strcpy(name, other.name);
            balance = other.balance;
        }
        return *this;
    }

    /**
     * Move Constructor
     * Transfers ownership of resources
     * instead of copying them.
     */
    Employee(Employee&& other) noexcept {
        name = other.name;
        balance = other.balance;

        other.name = nullptr;
        other.balance = 0;
    }

    /**
     * Move Assignment Operator
     * Releases current resource and
     * takes ownership of other's resource.
     */
    Employee& operator=(Employee&& other) noexcept {
        if (this != &other) {
            delete[] name;

            name = other.name;
            balance = other.balance;

            other.name = nullptr;
            other.balance = 0;
        }
        return *this;
    }

    void display() const {
        cout << (name ? name : "NULL") << " " << balance << endl;
    }

    ~Employee() {
        delete[] name;
    }
};

int main() {

    Employee e1("Prateek", 900);
    Employee e2, e3, e4, e5;

    e2 = e1;               // Copy assignment
    e3 = std::move(e2);    // Move assignment
    e4 = e3;               // Copy assignment
    e5 = std::move(e4);    // Move assignment

    e1.display();
    e2.display();
    e3.display();
    e4.display();
    e5.display();

    return 0;
}

/*
----------------------------------------
WHY RULE OF FIVE IS IMPORTANT?
----------------------------------------

If a class manages dynamic memory:

-> Default copy may cause shallow copy
-> Shallow copy causes double delete
-> Leads to crashes and undefined behavior

Rule of Five ensures:
- Proper deep copying
- Safe ownership transfer
- No memory leaks
- Efficient move semantics
*/
