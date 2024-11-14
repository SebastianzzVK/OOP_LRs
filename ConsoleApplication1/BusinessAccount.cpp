#include "BusinessAccount.h"

BusinessAccount::BusinessAccount(double balance, double creditLimit, const string& accountNumber, double overdraftLimit)
    : Account(balance, creditLimit, accountNumber), overdraftLimit(overdraftLimit) {
    cout << "BusinessAccount created" << endl;
    
}

// Реалізація деструктора
BusinessAccount::~BusinessAccount() {
    cout << "BusinessAccount destroyed." << endl;
}

bool BusinessAccount::overdraft(double amount) {
    if (getBalance() + overdraftLimit >= amount) {
        withdraw(amount);
        return true;
    }
    return false;
}
