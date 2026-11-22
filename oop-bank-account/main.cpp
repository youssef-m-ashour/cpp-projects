#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string owner;
    double balance;

public:
    BankAccount();
    BankAccount(string owner, double balance);

    void deposit(double amount);
    void withdraw(double amount);
    void display() const;
};

// Default constructor
BankAccount::BankAccount() {
    owner = "Unknown";
    balance = 0.0;
}

// Parameterized constructor using this pointer
BankAccount::BankAccount(string owner, double balance) {
    this->owner = owner;
    this->balance = balance;
}

// Deposit money
void BankAccount::deposit(double amount) {
    if (amount > 0) {
        balance += amount;
    } else {
        cout << "Invalid deposit amount!" << endl;
    }
}

// Withdraw money
void BankAccount::withdraw(double amount) {
    if (amount > 0 && amount <= balance) {
        balance -= amount;
    } else {
        cout << "Invalid withdrawal amount or insufficient balance!" << endl;
    }
}

// Display account info
void BankAccount::display() const {
    cout << "Owner: " << owner << endl;
    cout << "Balance: $" << balance << endl;
    cout << "----------------------" << endl;
}

int main() {
    BankAccount account1; // default constructor
    BankAccount account2("Youssef", 1000.0); // parameterized constructor

    cout << "Initial Accounts:" << endl;
    account1.display();
    account2.display();

    account2.deposit(500.0);
    account2.withdraw(200.0);

    cout << "Updated Second Account:" << endl;
    account2.display();

    return 0;
}