
/**
 * @file Singleton.cpp
 * @brief Demonstrates implementation of Singleton Design Pattern.
 *
 * Singleton ensures that only one instance of a class exists
 * and provides a global access point to that instance.
 */

#include <iostream>
using namespace std;

/**
 * @class Singleton
 * @brief A class that allows only one object to be created.
 */
class Singleton {
private:

    /**
     * @brief Static pointer that holds the single instance.
     */
    static Singleton* instance;

    /**
     * @brief Private constructor to prevent direct object creation.
     */
    Singleton() {
        cout << "Singleton Constructor Called\n";
    }

public:

    /**
     * @brief Returns the single instance of the class.
     *
     * If the instance does not exist, it creates one.
     * Otherwise, it returns the already created instance.
     *
     * @return Pointer to the Singleton object.
     */
    static Singleton* getInstance() {

        if (instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }

    /**
     * @brief Displays a confirmation message.
     */
    void show() {
        cout << "I am Singleton Object\n";
    }

    /**
     * @brief Destructor.
     */
    ~Singleton() {
        cout << "Singleton Destroyed\n";
    }
};

/**
 * @brief Initialize static member to nullptr.
 */
Singleton* Singleton::instance = nullptr;


/**
 * @brief Entry point of the program.
 *
 * Demonstrates that multiple calls to getInstance()
 * return the same object.
 */
int main() {

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->show();
    s2->show();

    cout << "Address of s1: " << s1 << endl;
    cout << "Address of s2: " << s2 << endl;

    return 0;
}


/*
BOTTOM LINE:-
Singleton Pattern:
Singleton ensures that a class has ONLY ONE object and provides a global access point to it.
Q1. Is Singleton object created at compile time?
No, it is created at runtime when getInstance() is called.
*/