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
    // ---------- Constructors ----------
    BankAccount() : accountHolder("Unknown"), balance(0.0), accountNumber(++nextID) {
        counter++;
        cout << "Default constructor called for account " << accountNumber << endl;
    }

    BankAccount(string name, double initialBalance = 0.0)
        : accountHolder(name), balance(initialBalance), accountNumber(++nextID) {
        counter++;
        cout << "Parameterized constructor called for account " << accountNumber << endl;
    }

    // ---------- Delete Copy ----------
    BankAccount(const BankAccount&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    // ---------- Move ----------
    BankAccount(BankAccount&& other)
        : accountHolder(move(other.accountHolder)), balance(other.balance), accountNumber(other.accountNumber) {
        counter++;
        other.balance = 0;
        other.accountNumber = 0;
        cout << "Move constructor called for account " << accountNumber << endl;
    }

    BankAccount& operator=(BankAccount&& other)  {
        if (this != &other) {
            accountHolder = move(other.accountHolder);
            balance = other.balance;
            accountNumber = other.accountNumber;
            other.balance = 0;
            other.accountNumber = 0;
        }
        return *this;
    }

    // ---------- Deposit / Withdraw ----------
    BankAccount& deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited " << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount!" << endl;
        }
        return *this;
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
        } else if (amount > balance) {
            cout << "Insufficient balance in account " << accountNumber << endl;
        } else {
            balance -= amount;
            cout << "Withdrew " << amount << " from account " << accountNumber << endl;
        }
    }

    double getBalance() const { return balance; }

    static void showCounter() {
        cout << "Total accounts created: " << counter << endl;
    }

    // ---------- Destructor ----------
    ~BankAccount() {
        cout << "Destructor called for account " << accountNumber << endl;
    }

    // ---------- Friend operators ----------
    friend ostream& operator<<(ostream& os, const BankAccount& acc);
    friend istream& operator>>(istream& is, BankAccount& acc);
};

// ---------- Static members ----------
int BankAccount::counter = 0;
int BankAccount::nextID = 0;

// ---------- Operator << ----------
ostream& operator<<(ostream& os, const BankAccount& acc) {
    os << "Account Information\n";
    os << "------------------------\n";
    os << "Account Holder: " << acc.accountHolder << "\n";
    os << "Account Number: " << acc.accountNumber << "\n";
    os << "Balance: " << acc.balance << "\n";
    os << "===============================\n";
    return os;
}

// ---------- Operator >> ----------
istream& operator>>(istream& is, BankAccount& acc) {
    cout << "Enter account holder name: ";
    is >> ws;
    getline(is, acc.accountHolder);
    cout << "Enter initial balance: ";
    is >> acc.balance;
    return is;
}

// ---------- MAIN ----------
int main() {
    cout << "--- Test Set for BankAccount ---\n";

    // Create accounts
    BankAccount acc1("Farida", 1000.0);
    BankAccount acc2("Omar", 500.0);
    BankAccount acc3("mariam",50.0);

    // Test deposit and withdraw
    acc1.deposit(200).deposit(300).withdraw(150);
    acc2.deposit(1000).withdraw(2000);

    // Test printing using operator<<
    cout << acc1;
    cout << acc2;
    cout << acc3;

    // Test input using operator>>
    BankAccount acc4;
    cin >> acc4;
    cout << "New account created via input:\n" << acc4;

    // Test move constructor
    BankAccount acc5 = std::move(acc4);
    cout << "Account after move:\n" << acc5;

    // Test move assignment
    BankAccount acc6("Temp", 100);
    acc6 = std::move(acc3);
    cout << "Account after move assignment:\n" << acc6;

    // Show total accounts
    BankAccount::showCounter();

    return 0;
}
