#include <iostream>

int main() {
    std::string name;
    int age;
    std::string city;

    std::cout << "Enter your name: ";
    std::cin >> name;
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Enter your city: ";
    std::cin >> city;

    std::cout << "My name is " << name << " I am " << age << " years old " << "I live in " << city << std::endl;

    int x, y;
    std::cout << "Enter two numbers: ";
    std::cin >> x >> y;
    std::cout << "Sum = " << x + y << std::endl;
    std::cout << "difference = " << x - y << std::endl;
    std::cout << "average = " << (x + y) / 2.0 << std::endl;

    int num;
    std::cout << "Enter a number: ";
    std::cin >> num;
    std::cout << "Hexa: " << std::hex << num << std::endl;
    std::cout << "Octal: " << std::oct << num << std::endl;

    char a;
    std::cout << "Enter a character: ";
    std::cin >> a;
    std::cout << "ASCII value = " << (int)a << std::endl;

    return 0;
}
