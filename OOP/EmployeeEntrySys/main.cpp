#include <iostream>
#include <conio.h>
#include <array>
#include <string>
using namespace std;

int main() {
    const int maxEmployees = 4;

    struct Employee {
        string id;
        string name;
        int age;
        float salary;
    };

    Employee employees[maxEmployees];
    int empCount = 0;

    while (true) {
        cout << "\033[2J\033[H";
        cout << "Enter Employee " << empCount + 1 << " Data:\n\n";
        cout << "ID:                        Name:\n";
        cout << "Age:                       Salary:\n";

        int idRow = 3, idCol = 5;
        int nameRow = 3, nameCol = 30;
        int ageRow = 4, ageCol = 5;
        int salaryRow = 4, salaryCol = 30;

        cout << "\033[" << idRow << ";" << idCol - 1 << "H";
        getline(cin >> ws, employees[empCount].id);

        cout << "\033[" << nameRow << ";" << nameCol + 3 << "H";
        getline(cin >> ws, employees[empCount].name);

        cout << "\033[" << ageRow << ";" << ageCol << "H";
        cin >> employees[empCount].age;

        cout << "\033[" << salaryRow << ";" << salaryCol + 5 << "H";
        cin >> employees[empCount].salary;

        empCount++;
        cin.ignore();

        cout << "\033[6;0H";
        cout << "Employee added successfully.\n";
        cout << "Press ENTER for new employee or ESC to finish.\n";

        while (true) {
            int c = _getch();
            if (c == 13) { // Enter
                break;
            } else if (c == 27) { // ESC
                cout << "\033[2J\033[H";
                cout << "Exiting...\n";
                cout << "Bye Bye!\n";
                return 0;
            }
        }

        if (empCount >= maxEmployees) {
            cout << "\033[2J\033[H";
            cout << "Maximum number of employees reached.\n";
            cout << "Bye Bye!\n";
            break;
        }
    }

    cout << "\nPress Enter to exit...";
    cin.get();
    return 0;
}
