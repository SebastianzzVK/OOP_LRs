#include "Account.h"

// 1. Реалізація конструктора без параметрів
Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("") {}

// 1. Реалізація конструктора з параметрами
Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {}

void Account::deposit(double amount) {
    // 4. Метод для внесення грошей
    balance += amount; // Додаємо суму до балансу
    transactions.push_back(amount); // Додаємо транзакцію до історії
    cout << "Deposited: $" << amount << " to account: " << accountNumber << endl;
}

bool Account::withdraw(double amount) {
    // 4. Метод для зняття грошей
    if (balance + creditLimit >= amount) {
        balance -= amount; // Зменшуємо баланс
        transactions.push_back(-amount); // Додаємо транзакцію до історії
        cout << "Withdrew: $" << amount << " from account: " << accountNumber << endl;
        return true; // Операція успішна
    }
    else {
        cout << "Insufficient funds for withdrawal from account: " << accountNumber << endl;
        return false; // Операція не вдалася
    }
}

double Account::getBalance() const {
    // 4. Метод для отримання балансу
    return balance; // Повертає баланс рахунку
}

void Account::saveToFile(const string& filename) const {
    // 5. Метод для запису даних рахунку у файл
    ofstream file(filename);
    if (file.is_open()) {
        file << balance << "\n" << creditLimit << "\n" << accountNumber << "\n";
        file.close();
    }
    else {
        cout << "Failed to open file for writing: " << filename << endl;
    }
}

void Account::loadFromFile(const string& filename) {
    // 5. Метод для читання даних рахунку з файлу
    ifstream file(filename);
    if (file.is_open()) {
        file >> balance >> creditLimit >> accountNumber;
        file.close();
    }
    else {
        cout << "Failed to open file for reading: " << filename << endl;
    }
}

void Account::displayTransactionHistory() const {
    // 4. Метод для відображення історії транзакцій
    cout << "Transaction history for account " << accountNumber << ":" << endl;
    for (const auto& transaction : transactions) {
        cout << (transaction > 0 ? "Deposited: $" : "Withdrew: $") << abs(transaction) << endl;
    }
}
