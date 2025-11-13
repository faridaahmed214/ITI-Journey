#include <iostream>
#include <string>
#include <conio.h>
#include <memory>

using namespace std;

struct Employee {
    string id;
    string name;
    int age;
    float salary;
};

unique_ptr<Employee[]> employees;
int empCount = 0;
int maxEmployees = 0;

void clearScreen() {
    cout << "\033[2J\033[H";
    cout.flush();
}

void addEmployee() {
    clearScreen();
    if (empCount >= maxEmployees) {
        cout << "Maximum number of employees reached.\n";
        cout << "(press any key to return to menu)";
        _getch();
        return;
    }
    cout << "Enter employee " << empCount + 1 << " data:\n\n";
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
    cin.ignore();

    empCount++;
    cout << "\033[6;0HEmployee added successfully.\n";
    cout << "(press any key to return to menu)";
    _getch();
}

void display() {
    clearScreen();
    if (empCount == 0) {
        cout << "No employees to display.\n";
        cout << "(press any key to return to menu)";
        _getch();
        return;
    }
    string searchID;
    cout << "Enter Employee ID to display: ";
    getline(cin >> ws, searchID);

    bool found = false;
    for (int i = 0; i < empCount; i++) {
        if (employees[i].id == searchID) {
            found = true;
            clearScreen();
            cout << "Employee Data:\n";
            cout << "-----------------------\n";
            cout << "ID: " << employees[i].id << endl;
            cout << "Name: " << employees[i].name << endl;
            cout << "Age: " << employees[i].age << endl;
            cout << "Salary: " << employees[i].salary << endl;
            break;
        }
    }
    if (!found)
        cout << "\nEmployee with ID \"" << searchID << "\" not found.\n";

    cout << "\n(press any key to return to menu)";
    _getch();
}

void displayAll() {
    clearScreen();
    if (empCount == 0) {
        cout << "No employees to display.\n";
        cout << "(press any key to return to menu)";
        _getch();
        return;
    }
    cout << "All Employees:\n";
    cout << "-----------------------------\n";
    for (int i = 0; i < empCount; i++) {
        cout << "Employee " << i + 1 << ":\n";
        cout << "ID: " << employees[i].id << endl;
        cout << "Name: " << employees[i].name << endl;
        cout << "Age: " << employees[i].age << endl;
        cout << "Salary: " << employees[i].salary << endl;
        cout << "-----------------------------\n";
    }
    cout << "(press any key to return to menu)";
    _getch();
}

void runMenu() {
    string menu[] = {"new", "display", "display all", "exit"};
    int n = 4;
    int selected = 0;
    int startRow = 5, startCol = 10;

    clearScreen();
    while (true) {
        for (int i = 0; i < n; i++) {
            int row = startRow + i;
            cout << "\033[" << row << ";" << startCol << "H";
            if (i == selected)
                cout << "\033[31m> " << menu[i] << "\033[0m";
            else
                cout << "  " << menu[i];
        }
        cout.flush();
        int c = _getch();
        if (c == 0 || c == 224) {
            int code = _getch();
            if (code == 72)
                selected = (selected - 1 + n) % n;
            else if (code == 80)
                selected = (selected + 1) % n;
        }
        else if (c == 13) { // Enter
            if (menu[selected] == "new")
                addEmployee();
            else if (menu[selected] == "display")
                display();
            else if (menu[selected] == "display all")
                displayAll();
            else if (menu[selected] == "exit") {
                clearScreen();
                cout << "Bye Bye!\n";
                break;
            }
            clearScreen();
        }
        else if (c == 27) {
            clearScreen();
            cout << "Bye Bye!\n";
            break;
        }
    }
}

int main() {
    cout << "Enter the number of employees: ";
    cin >> maxEmployees;
    cin.ignore();
    if (maxEmployees <= 0) {
        cout << "Invalid size!\n";
        return 0;
    }

    employees = make_unique<Employee[]>(maxEmployees);

    runMenu();
    return 0;
}
