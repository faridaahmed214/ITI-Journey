#include <iostream>
using namespace std;

void binary(int n) {
    if (n > 1)
        binary(n / 2);
    cout << n % 2;
}

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    binary(num);
    cout << endl;

    return 0;
}
