#include <iostream>
using namespace std;

class Stack {
private:
    int* arr;
    int top;
    int size;
    static int counter;

public:
    Stack(){
    size = 5;
    top = -1;
    arr = new int[size];
    counter++;

    };

    Stack(int capacity) {
        size = capacity;
        top = -1;
        arr = new int[size];
        counter++;
    }

    Stack& push(int num) {
        if (top == size - 1) {
            cout << "Stack overflow\n";
            return *this;
        }
        arr[++top] = num;
        return *this;
    }

    Stack& pop() {
        if (top == -1) {
            cout << "Stack is empty\n";
            return *this;
        }
        int val = arr[top];
        top--;
        return *this;
    }

    void showElements()  {
        if (top == -1) {
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    static void showCounter() {
        cout << "Number of Stack objects created: " << counter << endl;
    }

    ~Stack() {
        delete[] arr;
        counter--;
    }
};

int Stack::counter = 0;

int main() {
    Stack s1(5);
    s1.push(10).push(20).push(30).pop();
    s1.showElements();
    Stack::showCounter();
    Stack s2(3);
    Stack::showCounter();
    s2.push(7).push(60).push(10).pop().push(40);
    s2.showElements();
    s2.~Stack();
    Stack::showCounter();
    return 0;
}
