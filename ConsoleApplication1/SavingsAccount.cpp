#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(double balance, double creditLimit, const string& accountNumber)
    : Account(balance, creditLimit, accountNumber) {}

void SavingsAccount::addMonthlyInterest() {
    deposit(getBalance() * 0.02); // 2% нарахування
}
