#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H

#include "Account.h"
using namespace std;
class BusinessAccount : public Account {
private:
    double overdraftLimit;

public:
    
    BusinessAccount(double balance, double creditLimit, const string& accountNumber, double overdraftLimit);
        
    BusinessAccount(double initial_balance, const std::string& acc_number, double overdraft)
        : Account(initial_balance, acc_number), overdraftLimit(overdraft) {}

    bool overdraft(double amount);

     BusinessAccount();
    ~BusinessAccount();

      
    void accessBaseClassMembersGlobal() {
        
        cout << "Total Accounts (via global access): " << Account::getAccountCount() << endl;

        double balance = Account::getBalance();
        cout << "Balance (via global access): " << balance << endl;
    }

        using Account::deposit;
    
    void accessBaseClassMembersUsing() {
        
        deposit(100);
        cout << "Deposit of 100 made using 'using' operator. New Balance: " << getBalance() << endl;
    }
};

#endif // BUSINESSACCOUNT_H
