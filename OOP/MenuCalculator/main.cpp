#include <iostream>
using namespace std;

int main() {
    int num1, num2;
    char op;

    do {
        cout << "Enter first number: ";
        cin >> num1;
        cout << "\nEnter second number: ";
        cin >> num2;

        cout << "\nEnter operation:\n"
             << "  a or A for +\n"
             << "  b or B for -\n"
             << "  c or C for *\n"
             << "  d or D for /\n"
             << "  e or E to exit\n";
        cin >> op;

        switch (op) {
            case 'a': case 'A':
                cout << num1 << " + " << num2 << " = " << num1 + num2;
                break;
            case 'b': case 'B':
                cout << num1 << " - " << num2 << " = " << num1 - num2;
                break;
            case 'c': case 'C':
                cout << num1 << " * " << num2 << " = " << num1 * num2;
                break;
            case 'd': case 'D':
                if (num2 != 0)
                    cout << num1 << " / " << num2 << " = " << num1 / num2;
                else
                    cout << "Error: Division by zero!";
                break;
            case 'e': case 'E':
                cout << "Goodbye!" << endl;
                break;
            default:
                cout << "Invalid operation!";
        }
        cout << "\n\n";
    } while (op != 'e' && op != 'E');

    return 0;
}
