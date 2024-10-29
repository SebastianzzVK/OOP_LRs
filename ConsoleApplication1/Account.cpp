#include "Account.h"

// Ініціалізація статичного члена
int Account::accountCount = 0;

// 1. Конструктор без параметрів
Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("DEFAULT") {
    accountCount++; // Збільшення лічильника рахунків
}

// 1. Конструктор з параметрами
Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {
    accountCount++;
}

// 1. Конструктор копіювання
Account::Account(const Account& other)
    : balance(other.balance), creditLimit(other.creditLimit), accountNumber(other.accountNumber) {
    accountCount++;
}

// 3. Деструктор
Account::~Account() {
    accountCount--; // Зменшення лічильника рахунків при видаленні об'єкта
}

// Метод для внесення грошей
void Account::deposit(double amount) {
    balance += amount;
}

// Метод для зняття грошей
bool Account::withdraw(double amount) {
    if (balance + creditLimit >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// Метод для отримання балансу
double Account::getBalance() const {
    return balance;
}

// 4. Статичний метод для отримання кількості рахунків
int Account::getAccountCount() {
    return accountCount;
}
