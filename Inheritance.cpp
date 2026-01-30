/*
*************** Inheritance in CPP *************
*/
//Single Inheritance
//A derived class inherits from only one base class.
class Vehicle {
public:
    void start() {
        cout << "Vehicle started" << endl;
    }
};

class Car : public Vehicle {  // Single inheritance
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

int main() {
    Car myCar;
    myCar.start();  // Inherited from Vehicle
    myCar.drive();  // Defined in Car
    return 0;
}

//2. Multiple Inheritance
//A derived class inherits from more than one base class.

class Engine {
public:
    void engineInfo() {
        cout << "Engine: V8" << endl;
    }
};

class Wheels {
public:
    void wheelInfo() {
        cout << "Wheels: 4" << endl;
    }
};

class Car : public Engine, public Wheels {  // Multiple inheritance
public:
    void carInfo() {
        cout << "This is a car" << endl;
    }
};

int main() {
    Car myCar;
    myCar.engineInfo();  // From Engine
    myCar.wheelInfo();   // From Wheels
    myCar.carInfo();     // From Car
    return 0;
}

//**3. Multilevel Inheritance**
//A class is derived from another derived class, creating a chain of inheritance.

class Vehicle {
public:
    void vehicleType() {
        cout << "This is a vehicle" << endl;
    }
};

class Car : public Vehicle {  // Car inherits from Vehicle
public:
    void carType() {
        cout << "This is a car" << endl;
    }
};

class SportsCar : public Car {  // SportsCar inherits from Car
public:
    void sportsCarType() {
        cout << "This is a sports car" << endl;
    }
};

int main() {
    SportsCar myCar;
    myCar.vehicleType();    // From Vehicle
    myCar.carType();        // From Car
    myCar.sportsCarType();  // From SportsCar
    return 0;
}

//**4. Hierarchical Inheritance**
//Multiple derived classes inherit from a single base class.
class Animal {
public:
    void eat() {
        cout << "Eating..." << endl;
    }
};

class Dog : public Animal {  // Dog inherits from Animal
public:
    void bark() {
        cout << "Barking..." << endl;
    }
};

class Cat : public Animal {  // Cat also inherits from Animal
public:
    void meow() {
        cout << "Meowing..." << endl;
    }
};

int main() {
    Dog myDog;
    Cat myCat;
    myDog.eat();  // Inherited from Animal
    myDog.bark();
    myCat.eat();  // Inherited from Animal
    myCat.meow();
    return 0;
}

//**Hybrid Inheritance**
//A combination of two or more types of inheritance.
//This can lead to the **diamond problem**, which is resolved using virtual inheritance

class Vehicle {
public:
    void start() {
        cout << "Vehicle started" << endl;
    }
};

class Car : virtual public Vehicle {  // Virtual inheritance
public:
    void drive() {
        cout << "Car is driving" << endl;
    }
};

class Boat : virtual public Vehicle {  // Virtual inheritance
public:
    void sail() {
        cout << "Boat is sailing" << endl;
    }
};

class AmphibiousVehicle : public Car, public Boat {  // Hybrid inheritance
public:
    void operate() {
        cout << "Operating amphibious vehicle" << endl;
    }
};

int main() {
    AmphibiousVehicle av;
    av.start();    // Only one copy due to virtual inheritance
    av.drive();
    av.sail();
    av.operate();
    return 0;
}
