#include <iostream>
using namespace std;

class Complex {
private:
    float real = 0;
    float imag = 0;
    static int counter;

    struct CounterHelper {
        CounterHelper() {
            Complex::counter++;
        }
    };

    CounterHelper helper;

public:
    Complex()= default;
    Complex(float r) {
        real = r;
        imag = 0;
        cout << "Overloaded constructor Complex(float) is called." << endl;
    }

    Complex(float r, float i) : real(r), imag(i) {
        cout << "Overloaded constructor Complex(float, float) is called." << endl;
    }

    ~Complex() {
        --counter;
    }

    void printComplex() const {
        if (real == 0 && imag == 0)
            cout << "0";
        else if (real == 0) {
            if (imag == 1)
                cout << "i";
            else if (imag == -1)
                cout << "-i";
            else
                cout << imag << "i";
        } else if (imag == 0)
            cout << real;
        else {
            cout << real;
            if (imag > 0)
                cout << "+";
            if (imag == 1)
                cout << "i";
            else if (imag == -1)
                cout << "-i";
            else
                cout << imag << "i";
        }
    }

    static void showCounter() {
        cout << "Number of active Complex objects: " << counter << endl;
    }
};

int Complex::counter = 0;

int main() {
    Complex c1(5,7);
    Complex c2(-3, -3);
    Complex c3(0, 8);
    Complex c4(0, -8);
    Complex c5(0, -9);
    Complex c6(-9, 3);
    Complex c7(8, 1);

    cout << "\nValues of Complex numbers:\n";
    cout << "c1 = "; c1.printComplex(); cout << endl;
    cout << "c2 = "; c2.printComplex(); cout << endl;
    cout << "c3 = "; c3.printComplex(); cout << endl;
    cout << "c4 = "; c4.printComplex(); cout << endl;
    cout << "c5 = "; c5.printComplex(); cout << endl;
    cout << "c6 = "; c6.printComplex(); cout << endl;
    cout << "c7 = "; c7.printComplex(); cout << endl;

    cout << "\n";
    Complex::showCounter();

    return 0;
}
