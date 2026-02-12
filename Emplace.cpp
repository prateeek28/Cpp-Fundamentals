/*
TOPIC: Emplace vs Push_Back
->emplace constructs the object directly inside the container.
->push_back first creates an object, then inserts it.(Extra Step Involved)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Student
{
public:
    string name;
    int age;

    // Constructor
    Student(string n, int a)
    {
        cout << "Constructor Called\n";
        name = n;
        age = a;
    }
};

int main()
{
    vector<Student> students;

    cout << "Using push_back:\n";

    // First creates object, then pushes into vector
    students.push_back(Student("Pratik", 23));

    cout << "\nUsing emplace_back:\n";

    // Directly constructs object inside vector
    students.emplace_back("Rahul", 25);

    return 0;
}
