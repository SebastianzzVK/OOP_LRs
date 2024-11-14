#include "CreditCardAccount.h"

CreditCardAccount::CreditCardAccount(double balance, double creditLimit, const string& accountNumber, double interestRate)
    : Account(balance, creditLimit, accountNumber), creditLimit(interestRate) {
    cout << "CreditCardAccount constructor called." << endl;

}

void CreditCardAccount::applyInterest() {
    deposit(getBalance() * creditLimit / 100);
}
