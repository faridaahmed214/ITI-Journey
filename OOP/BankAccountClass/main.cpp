#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int accountNumber;
    double balance;

    static int counter;
    static int nextID;

public:
    BankAccount() {
        accountHolder = "Unknown";
        balance = 0.0;
        accountNumber = ++nextID;
        counter++;
        cout << "Default constructor called for account " << accountNumber << endl;
    }

    BankAccount(string name, double initialBalance = 0.0){
        accountHolder = name;
        balance = initialBalance;
        accountNumber = ++nextID;
        counter++;
        cout << "Parameterized constructor called for account " << accountNumber << endl;
    }

    BankAccount& deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!\n";
        }
        return *this;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!\n";
        } else if (amount > balance) {
            cout << "Insufficient balance in account " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        }
    }

    void showAccount()  {
        cout << "\nAccount Information"<<endl;
        cout<<"------------------------"<<endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: " << balance << endl;
        cout<<"==============================="<<endl;
    }

    double getBalance()  {
        return balance;
    }

    static void showCounter() {
        cout << "Total accounts created: " << counter << endl;
    }

    ~BankAccount() {
        cout << "Destructor called for account " << accountNumber << endl;
    }
};

int BankAccount::counter = 0;
int BankAccount::nextID = 0;

int main() {

    BankAccount acc1("farida", 1000.0);
    BankAccount acc2("Omar", 500.0);
    BankAccount acc3;

    acc1.deposit(200).deposit(300).withdraw(150);
    acc2.deposit(1000).withdraw(2000);
    acc3.deposit(50);

    acc1.showAccount();
    acc2.showAccount();
    acc3.showAccount();

    BankAccount::showCounter();

    return 0;
}
