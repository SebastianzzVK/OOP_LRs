#include "Account.h"

// Ініціалізація статичного члена
int Account::accountCount = 0;

// 1. Конструктор без параметрів
Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("DEFAULT") {
    accountCount++; // Збільшення лічильника рахунків
    cout << "Account constructor called." << endl;
    cout << "Account parameterized constructor called." << endl;
    cout << "Account destructor called." << endl;
}

// 1. Конструктор з параметрами
Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}

// 1. Конструктор копіювання
Account::Account(const Account& other)
    : balance(other.balance), creditLimit(other.creditLimit), accountNumber(other.accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}

// 3. Деструктор
Account::~Account() {
    accountCount--;
    cout << "Account destroyed. Account count: " << accountCount << endl;
}


// Метод для отримання балансу
double Account::getBalance() const {
    return balance;
}

// 4. Статичний метод для отримання кількості рахунків
int Account::getAccountCount() {
    return accountCount;
}
