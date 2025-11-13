#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;
    static int counter;

public:
    // ---------- Delete default constructor ----------
    Stack() = delete;

    // ---------- Parameterized constructor ----------
    Stack(int capacity = 5) : size(capacity), top(-1) {
        arr = new int[size];
        counter++;
        cout << "Parameterized constructor called for Stack object\n";
    }

    // ---------- Copy constructor ----------
    Stack(const Stack& other) : size(other.size), top(other.top) {
        arr = new int[size];
        for (int i = 0; i <= top; ++i)
            arr[i] = other.arr[i];
        counter++;
        cout << "Copy constructor called\n";
    }

    // ---------- Move constructor ----------
    Stack(Stack&& other) : arr(other.arr), top(other.top), size(other.size) {
        other.arr = nullptr;
        other.top = -1;
        other.size = 0;
        counter++;
        cout << "Move constructor called\n";
    }

    // ---------- Copy assignment ----------
    Stack& operator=(const Stack& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            top = other.top;
            arr = new int[size];
            for (int i = 0; i <= top; ++i)
                arr[i] = other.arr[i];
        }
        cout << "Copy assignment called\n";
        return *this;
    }

    // ---------- Move assignment ----------
    Stack& operator=(Stack&& other)  {
        if (this != &other) {
            delete[] arr;
            arr = other.arr;
            top = other.top;
            size = other.size;
            other.arr = nullptr;
            other.top = -1;
            other.size = 0;
        }
        cout << "Move assignment called\n";
        return *this;
    }

    // ---------- Push / Pop ----------
    Stack& push(int num) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
        } else {
            arr[++top] = num;
        }
        return *this;
    }

    Stack& pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
        } else {
            --top;
        }
        return *this;
    }

    // ---------- Overload [] ----------
    int& operator[](int index) {
        if (index < 0 || index > top) {
            cout << "Index out of range, returning first element\n";
            return arr[0];
        }
        return arr[index];
    }

    // ---------- Overload << ----------
    friend ostream& operator<<(ostream& os, const Stack& s) {
        if (s.top == -1) {
            os << "Stack is empty\n";
        } else {
            os << "Stack elements: ";
            for (int i = 0; i <= s.top; ++i)
                os << s.arr[i] << " ";
            os << endl;
        }
        return os;
    }

    // ---------- Overload >> ----------
    friend istream& operator>>(istream& is, Stack& s) {
        int n;
        cout << "Enter number to push into stack: ";
        is >> n;
        s.push(n);
        return is;
    }

    // ---------- Destructor ----------
    ~Stack() {
        delete[] arr;
        counter--;
        cout << "Destructor called, remaining Stack objects: " << counter << endl;
    }

    // ---------- Static counter ----------
    static void showCounter() {
        cout << "Number of Stack objects: " << counter << endl;
    }
};

int Stack::counter = 0;

// ---------- MAIN TEST ----------
int main() {
    cout << "--- Stack Test ---\n";

    Stack s1(5);
    s1.push(10).push(20).push(30).pop();
    cout << s1;

    Stack::showCounter();

    Stack s2(3);
    Stack::showCounter();
    s2.push(7).push(60).push(10).pop().push(40);
    cout << s2;

    // Test copy constructor
    Stack s3 = s1;
    cout << "Copied stack s3 from s1:\n" << s3;

    // Test move constructor
    Stack s4 = std::move(s2);
    cout << "Moved stack s2 into s4:\n" << s4;

    // Test copy assignment
    Stack s5(4);
    s5 = s1;
    cout << "After copy assignment s5 = s1:\n" << s5;

    // Test move assignment
    Stack s6(4);
    s6 = std::move(s1);
    cout << "After move assignment s6 = move(s1):\n" << s6;

    // Test [] operator
    cout << "s6[0] = " << s6[0] << endl;

    // Test input >>
    cin >> s6;
    cout << "s6 after input:\n" << s6;

    Stack::showCounter();

    return 0;
}
