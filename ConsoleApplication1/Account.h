#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    double balance; // Поле даних для балансу рахунку
    double creditLimit; // Поле даних для кредитного ліміту
    string accountNumber; // Поле даних для номеру рахунку
    static int accountCount; // Статичне поле для підрахунку рахунків

public:
    Account(); // 1. Конструктор без параметрів
    Account(double balance, double creditLimit, const string& accountNumber); // 1. Конструктор з параметрами
    Account(const Account& other); // 1. Конструктор копіювання

    

    void deposit(double amount); // Метод для внесення грошей
    bool withdraw(double amount); // Метод для зняття грошей
    double getBalance() const; // Метод для отримання балансу
    static int getAccountCount(); // Статичний метод для отримання кількості рахунків
    ~Account(); // 3. Деструктор
};

#endif // ACCOUNT_H
