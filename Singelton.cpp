/*
Singleton Pattern:
Singleton ensures that a class has ONLY ONE object and provides a global access point to it.
Is Singleton object created at compile time?
No, it is created at runtime when getInstance() is called.
*/




#include <iostream>
using namespace std;

class Singleton {
private:
    // Step 1: static pointer to hold single instance
    static Singleton* instance;

    // Step 2: private constructor
    // so object cannot be created from outside
    Singleton() {
        cout << "Singleton Constructor Called\n";
    }

public:
    // Step 3: public static function
    // this gives access to the single object
    static Singleton* getInstance() {

        // object created only once
        if (instance == nullptr) {
            instance = new Singleton();
        }

        return instance;
    }

    // simple function
    void show() {
        cout << "I am Singleton Object\n";
    }
};

// Step 4: initialize static member
Singleton* Singleton::instance = nullptr;

int main() {

    Singleton* s1 = Singleton::getInstance();
    Singleton* s2 = Singleton::getInstance();

    s1->show();
    s2->show();

    // both addresses are SAME
    cout << s1 << endl;
    cout << s2 << endl;

    return 0;
}
