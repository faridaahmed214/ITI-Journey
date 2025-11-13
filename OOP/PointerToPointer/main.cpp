#include <iostream>
#include <memory>
using namespace std;

int main() {
    cout << "=== RAW POINTER EXAMPLE ===\n";
    int x = 42;
    int* p = &x;
    int** pp = &p;

    cout << "x = " << x << "  (address of x = " << &x << ")" << endl;
    cout << "*p = " << *p << "  (address stored in p = " << p << ", address of p = " << &p << ")" << endl;
    cout << "**pp = " << **pp << "  (address stored in *pp = " << *pp << ", address of pp = " << &pp << ")" << endl;

    **pp = 100;
    cout << "x after change = " << x << endl;

    cout << "\n=== MODERN POINTER EXAMPLE ===\n";
    unique_ptr<int> ptr = make_unique<int>(5);
    unique_ptr<int> *ptr2 = &ptr;

    cout << "value in main pointer = " << *ptr << endl;
    cout << "address in smart pointer = " << **ptr2 << endl;

    cout << "address stored in main ptr  = " << ptr.get() << endl << endl;

    cout << "address of main_ptr(&ptr) = " << &ptr << endl;
    cout << "address stored in ptr2 = " << ptr2 << endl;


    return 0;
}
