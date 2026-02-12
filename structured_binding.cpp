/*
@File Structure_binding.cpp
Example: Employee Salary Analyzer
This demonstrates:
std::pair
std::tuple
Structured bindings in map loop
*/

#include <iostream>
#include <map>
#include <tuple>
using namespace std;

/*
    Function that calculates:
    - yearly salary
    - bonus (10%)
    - total compensation
    Returns multiple values using std::tuple
*/
tuple<double, double, double> calculateSalary(double monthlySalary)
{
    double yearly = monthlySalary * 12;
    double bonus = yearly * 0.10;
    double totalComp = yearly + bonus;

    return {yearly, bonus, totalComp};
}

int main()
{
    // Map storing EmployeeID -> Monthly Salary
    map<int, double> employees = {
        {101, 50000},
        {102, 65000},
        {103, 80000}
    };

    cout << " Employee Salary Report "<< endl;

    /*
        Structured binding in range-based loop.
        Instead of using:
            it.first, it.second
        We directly unpack id and salary.
    */
    for (const auto& [id, monthlySalary] : employees)
    {
        
          //Unpacking tuple returned from function.
        
        auto [yearly, bonus, total] = calculateSalary(monthlySalary);

        cout << "Employee ID : " << id << endl;
        cout << "Yearly      : " << yearly << endl;
        cout << "Bonus       : " << bonus << endl;
        cout << "Total Comp  : " << total << endl;
    }

    return 0;
}

/*
Bottom Line:
1. Introduced in C++17 – Used to unpack multiple values into separate variables.
2. Works with pair, tuple, map, arrays, and structs (public members).
3. Improves readability — avoids using .first, .second, get<>().
4. Default behavior is copy → use auto& if you want a reference.
5. Common real use:
for (const auto& [key, value] : myMap)
auto [a, b, c] = myTuple;
*/