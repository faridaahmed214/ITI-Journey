#include <iostream>
using namespace std;

int main() {
    int grade;
    cout << "please enter your grade: ";
    cin >> grade;

    if (grade <= 100 && grade >= 85)
        cout << "your grade is A\n";
    else if (grade <= 84 && grade >= 75)
        cout << "your grade is B\n";
    else if (grade <= 74 && grade >= 65)
        cout << "your grade is C\n";
    else if (grade <= 64 && grade >= 60)
        cout << "your grade is D\n";
    else if (grade < 60)
        cout << "your grade is F\n";
    else
        cout << "invalid grade as it exceeds 100\n";

    return 0;
}
