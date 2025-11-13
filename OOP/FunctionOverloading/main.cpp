#include <iostream>
using namespace std;

int sum(int a, int b) {
    cout << "Using int sum function" << endl;
    return a + b;
}

double sum(double a, double b) {
    cout << "Using double sum function" << endl;
    return a + b;
}

int main() {
    int intResult = sum(5, 10);
    cout << "Integer Sum: " << intResult << endl;

    double doubleResult = sum(5.5, 10.2);
    cout << "Double Sum: " << doubleResult << endl;

    return 0;
}
