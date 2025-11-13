#include <iostream>
using namespace std;

struct employee {
    string name;
    int age;
    int salary;

    void displayData() {
        cout << "Employee name: " << name
             << "\nAge: " << age
             << "\nSalary: " << salary << endl;
    }
};

class EmployeeClass {
public:
    string name;
    int age;
    int salary;

    void displayData() {
        cout << "Employee name: " << name
             << "\nAge: " << age
             << "\nSalary: " << salary << endl;
    }
};

int main() {
    employee emp1;
    emp1.name = "Farida";
    emp1.age = 21;
    emp1.salary = 100000;
    cout << "=== Struct Employee ===\n";
    emp1.displayData();

    cout << "\n-----------------------------\n";

    EmployeeClass emp2;
    emp2.name = "Malak";
    emp2.age = 25;
    emp2.salary = 105000;
    cout << "=== Class Employee ===\n";
    emp2.displayData();

    return 0;
}
