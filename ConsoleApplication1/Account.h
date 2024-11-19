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

};

#endif 
