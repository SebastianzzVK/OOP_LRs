#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include "Account.h"
using namespace std;
class SavingsAccount : public Account {
public:

    double interestRate;
    SavingsAccount(double balance, double creditLimit, const string& accountNumber);
    
    SavingsAccount(double initial_balance, const std::string& acc_number, double rate)
        : Account(initial_balance, acc_number), interestRate(rate) {}

    //Пункт 7
    SavingsAccount() : Account() {
        cout << "SavingsAccount constructor called." << endl;
    }
    SavingsAccount(double balance, double creditLimit, const string& accountNumber, double interestRate)
        : Account(balance, creditLimit, accountNumber) {
        cout << "SavingsAccount parameterized constructor called." << endl;
    }
    ~SavingsAccount() {
        cout << "SavingsAccount destructor called." << endl;
    }

    

    void addMonthlyInterest();
};

#endif // SAVINGSACCOUNT_H
