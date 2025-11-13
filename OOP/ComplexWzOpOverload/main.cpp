#include <iostream>
#include <cmath>
using namespace std;

class Complex {
private:
    float real{0.0f};
    float imag{0.0f};
    static int counter;

    struct CounterHelper {
        CounterHelper() { Complex::counter++; }
    };
    CounterHelper helper;

    float magnitudeSq() const {
        return real * real + imag * imag;
    }

public:
    // ---------- Constructors ----------
    Complex() = default;

    Complex(float r) : real{r}, imag{0.0f} {
        cout << "Overloaded constructor Complex(float) called." << endl;
    }

    Complex(float r, float i) : real{r}, imag{i} {
        cout << "Overloaded constructor Complex(float, float) called." << endl;
    }

    // ---------- Copy Constructor ----------
    Complex(const Complex& other) : real(other.real), imag(other.imag) {
        counter++;
        cout << "Copy constructor called." << endl;
    }

    // ---------- Move Constructor ----------
    Complex(Complex&& other) : real(other.real), imag(other.imag) {
        counter++;
        cout << "Move constructor called." << endl;
        other.real = 0;
        other.imag = 0;
    }

    // ---------- Assignment Operators ----------
    Complex& operator=(const Complex& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
        }
        return *this;
    }

    Complex& operator=(Complex&& other) {
        if (this != &other) {
            real = other.real;
            imag = other.imag;
            other.real = 0;
            other.imag = 0;
        }
        return *this;
    }

    // ---------- Destructor ----------
    ~Complex() {
        cout << "Destructor called for " << *this << endl;
        if(counter > 0) counter--;
        cout << "Active objects: " << counter << endl;
    }

    // ---------- Static counter ----------
    static void showCounter() {
        cout << "Number of active Complex objects: " << counter << endl;
    }

    // ---------- Arithmetic Operators ----------
    Complex operator+(const Complex& rhs) const { return Complex(real + rhs.real, imag + rhs.imag); }
    Complex operator-(const Complex& rhs) const { return Complex(real - rhs.real, imag - rhs.imag); }
    Complex operator*(const Complex& rhs) const {
        float r = (real * rhs.real) - (imag * rhs.imag);
        float i = (real * rhs.imag) + (imag * rhs.real);
        return Complex(r, i);
    }
    Complex operator/(const Complex& rhs) const {
        float denom = rhs.magnitudeSq();
        if (denom == 0) {
            cout << "Error: Division by zero!" << endl;
            return Complex();
        }
        float r = (real * rhs.real + imag * rhs.imag) / denom;
        float i = (imag * rhs.real - real * rhs.imag) / denom;
        return Complex(r, i);
    }

    // ---------- Relational Operators ----------
    bool operator>(const Complex& rhs) const { return magnitudeSq() > rhs.magnitudeSq(); }
    bool operator<(const Complex& rhs) const { return magnitudeSq() < rhs.magnitudeSq(); }
    bool operator==(const Complex& rhs) const { return real == rhs.real && imag == rhs.imag; }

    // ---------- Increment/Decrement ----------
    Complex& operator++() { real++; return *this; }
    Complex operator++(int) { Complex temp = *this; real++; return temp; }
    Complex& operator--() { real--; return *this; }
    Complex operator--(int) { Complex temp = *this; real--; return temp; }

    // ---------- Type Casting ----------
    operator double() const { return sqrt(magnitudeSq()); }

    // ---------- Friend Operators ----------
    friend ostream& operator<<(ostream& os, const Complex& c);
    friend istream& operator>>(istream& is, Complex& c);
};

// ---------- Static member ----------
int Complex::counter{0};

// ---------- Operator << ----------
ostream& operator<<(ostream& os, const Complex& c) {
    if (c.real == 0 && c.imag == 0)
        os << "0";
    else if (c.real == 0) {
        if (c.imag == 1)
            os << "i";
        else if (c.imag == -1)
            os << "-i";
        else
            os << c.imag << "i";
    }
    else if (c.imag == 0)
        os << c.real;
    else {
        os << c.real;
        if (c.imag > 0)
            os << " + ";
        else
            os << " - ";

        float absImag = fabs(c.imag);
        if (absImag == 1)
            os << "i";
        else
            os << absImag << "i";
    }
    return os;
}

// ---------- Operator >> ----------
istream& operator>>(istream& instream, Complex& c) {
    cout << "Enter real part: ";
    instream >> c.real;
    cout << "Enter imaginary part: ";
    instream >> c.imag;
    return is;
}

int main() {
    cout << "--- Object Creation (Test set) ---\n";
    Complex c1(5, 7);
    Complex c2(-3, -3);
    Complex c3(0, 8);
    Complex c4(0, -8);
    Complex c5(0, -9);
    Complex c6(-9, 3);
    Complex c7(8, 1);

    cout << "\nValues of Complex numbers:\n";
    cout << "c1 = "<<c1<< endl;
    cout << "c2 = "<<c2<< endl;
    cout << "c3 = "<<c3<< endl;
    cout << "c4 = "<<c4<< endl;
    cout << "c5 = "<<c5<< endl;
    cout << "c6 = "<<c6<< endl;
    cout << "c7 = "<<c7<< endl;

    cout << "\n--- Arithmetic Operators Test ---\n";
    Complex res_add = c1 + c2;
    cout << "c1 + c2 = " << res_add << endl;

    Complex res_sub = c1 - c2;
    cout << "c1 - c2 = " << res_sub << endl;

    Complex res_mul = c1 * c2;
    cout << "c1 * c2 = " << res_mul << endl;

    Complex res_div = c1 / c2;
    cout << "c1 / c2 = " << res_div << endl;

    cout << "\n--- Relational Operators Test ---\n";
    cout << "Is c1 > c3? " << (c1 > c3 ? "True" : "False") << endl;
    cout << "Is c1 < c3? " << (c1 < c3 ? "True" : "False") << endl;
    cout << "Is c1 == c1? " << (c1 == c1 ? "True" : "False") << endl;

    cout << "\n--- Increment/Decrement Operators Test ---\n";
    cout << "Original c3 = " << c3 << endl;

    Complex c8 = ++c3; // Pre-increment
    cout << "After ++c3, c3 = " << c3 << endl;
    cout << "After ++c3, c8 = " << c8 << endl;

    Complex c9 = c3++; // Post-increment
    cout << "After c3++, c3 = " << c3 << endl;
    cout << "After c3++, c9 = " << c9 << endl;

    cout << "\n--- Type Casting Test ---\n";
    double mag_c1 = static_cast<double>(c1);
    cout << "Magnitude of c1 = " << mag_c1 << endl;

    cout << "\n------------------------------------" << endl;
    cout << "--- Interactive Complex Calculator ---" << endl;

    Complex userInput1, userInput2;
    cout << "\nPlease enter the first complex number (u1):" << endl;
    cin >> userInput1;

    cout << "\nPlease enter the second complex number (u2):" << endl;
    cin >> userInput2;

    cout << "\n--- Calculation Results ---" << endl;
    cout << "(" << userInput1 << ") + (" << userInput2 << ") = " << (userInput1 + userInput2) << endl;
    cout << "(" << userInput1 << ") - (" << userInput2 << ") = " << (userInput1 - userInput2) << endl;
    cout << "(" << userInput1 << ") * (" << userInput2 << ") = " << (userInput1 * userInput2) << endl;
    cout << "(" << userInput1 << ") / (" << userInput2 << ") = " << (userInput1 / userInput2) << endl;
    cout << "------------------------------------" << endl;

    cout << "\nFinal count before destructors: ";
    Complex::showCounter();

    return 0;
}
