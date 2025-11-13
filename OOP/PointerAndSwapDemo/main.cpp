#include <iostream>
using namespace std;

// Pass by Address
void swapByAddress(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Pass by Reference
void swapByReference(int& x, int& y) {
    int temp = x;
    x = y;
    y = temp;
}

int main() {
    int a = 5, b = 10;
    cout << "Before swap: a = " << a << ", b = " << b << endl;

    swapByAddress(&a, &b);
    cout << "After swap by address: a = " << a << ", b = " << b << endl;

    swapByReference(a, b);
    cout << "After swap by reference: a = " << a << ", b = " << b << endl;

    int arr[5] = {1, 2, 3, 4, 5};
    cout << "\nArray elements using pointers: ";
    int* ptr = arr;
    for (int i = 0; i < 5; i++)
        cout << *(ptr + i) << " ";

    cout << endl;
    return 0;
}
