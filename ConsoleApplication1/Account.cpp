#include "Account.h"


int Account::accountCount = 0;


Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("DEFAULT") {
    accountCount++; 
    cout << "Account constructor called." << endl;
    cout << "Account parameterized constructor called." << endl;
    cout << "Account destructor called." << endl;
}


Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}


Account::Account(const Account& other)
    : balance(other.balance), creditLimit(other.creditLimit), accountNumber(other.accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}


Account::~Account() {
    accountCount--;
    cout << "Account destroyed. Account count: " << accountCount << endl;
}



double Account::getBalance() const {
    return balance;
}


int Account::getAccountCount() {
    return accountCount;
}
