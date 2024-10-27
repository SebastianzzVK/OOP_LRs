#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1. Визначити клас Account
class Account {
private:
    double balance;           // Приватне поле для зберігання балансу
    double creditLimit;       // Приватне поле для зберігання кредитного ліміту
    string accountNumber;     // Приватне поле для зберігання номера рахунку
    vector<double> transactions; // Приватне поле для зберігання історії транзакцій

public:
    Account(); // Конструктор без параметрів
    Account(double balance, double creditLimit, const string& accountNumber); // Конструктор з параметрами

    // 4. Метод для внесення грошей
    void deposit(double amount);

    // 4. Метод для зняття грошей
    bool withdraw(double amount);

    // 4. Метод для отримання балансу
    double getBalance() const;

    // 5. Метод для запису даних рахунку у файл
    void saveToFile(const string& filename) const;

    // 5. Метод для читання даних рахунку з файлу
    void loadFromFile(const string& filename);

    // 4. Метод для відображення історії транзакцій
    void displayTransactionHistory() const;
};

#endif // ACCOUNT_H
