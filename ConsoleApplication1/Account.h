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
   
    static int accountCount;
    

protected:
    string bankName; 
    string branchCode; 
     

public:
    string accountNumber;
    Account();
    Account(double balance, double creditLimit, const string& accountNumber); 
    Account(const Account& other); 
    virtual ~Account(); 

    string accountType;
    string accountHolder; 
    
    double getBalance() const;
    static int getAccountCount(); 
    



    Account(double initial_balance, const std::string& acc_number)
        : balance(initial_balance), accountNumber(acc_number) {
        accountCount++;
    }

    virtual void deposit(double amount) {
        balance += amount;
    }

    virtual bool withdraw(double amount) {
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


    // Перевантаження операторів
    Account& operator++();    // Префіксний оператор
    Account operator++(int);  // Постфіксний оператор
    Account& operator--();    // Префіксний оператор
    Account operator--(int);  // Постфіксний оператор

    // Перевантаження бінарних операторів
    Account operator+(double amount) const; // Додавання до балансу
    Account operator-(double amount) const; // Віднімання з балансу

    // Перевантаження операторів
    Account& operator=(const Account& other); // Оператор присвоєння
    Account& operator+=(double amount);
    Account& operator-=(double amount);
    Account& operator*=(double factor);
    Account operator*(double factor) const;
    char& operator[](size_t index); // Оператор доступу до символу

    // Шаблонна функція
    template <typename T>
    T compareValues(const T& a, const T& b) const {
        return (a > b) ? a : b;
    }
};

#endif 
