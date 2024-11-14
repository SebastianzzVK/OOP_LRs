#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    double balance;
    double creditLimit;
    string accountNumber;
    static int accountCount;
    

protected:
    string bankName; // Назва банку
    string branchCode; // Код філії банку
     

public:
    Account(); // 1. Конструктор без параметрів
    Account(double balance, double creditLimit, const string& accountNumber); // 1. Конструктор з параметрами
    Account(const Account& other); 
    virtual ~Account();  // Віртуальний деструктор для правильного видалення об'єктів

    string accountType; // Тип рахунку (наприклад, поточний, депозитний)
    string accountHolder; // Власник рахунку
    
    double getBalance() const; // Метод для отримання балансу
    static int getAccountCount(); // Статичний метод для отримання кількості рахунків
    



    Account(double initial_balance, const std::string& acc_number)
        : balance(initial_balance), accountNumber(acc_number) {
        accountCount++;
    }

    virtual void deposit(double amount) {// Метод для внесення грошей
        balance += amount;
    }

    virtual bool withdraw(double amount) { // Метод для зняття грошей
        if (balance >= amount) {
            balance -= amount;
            return true;
        }
        else {
            std::cout << "Недостатньо коштів для зняття!" << std::endl;
            return false;
        }
    }

    virtual void display_balance() const {
        std::cout << "Баланс акаунту " << accountNumber << ": " << balance << std::endl;
    }

};

#endif // ACCOUNT_H
