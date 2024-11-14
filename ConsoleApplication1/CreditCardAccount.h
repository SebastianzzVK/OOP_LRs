#ifndef CREDITCARDACCOUNT_H
#define CREDITCARDACCOUNT_H

#include "Account.h"
using namespace std;

class CreditCardAccount : public Account {
private:
    double creditLimit;

public:
    CreditCardAccount(double initial_balance, const std::string& acc_number, double limit)
        : Account(initial_balance, acc_number), creditLimit(limit) {}


    //Пункт 7
    CreditCardAccount() : Account() {
        cout << "CreditCardAccount constructor called." << endl;
    }
    CreditCardAccount(double balance, double creditLimit, const string& accountNumber, double creditCardLimit);
       
    ~CreditCardAccount() {
        cout << "CreditCardAccount destructor called." << endl;
    }
    void applyInterest(); // Нарахування відсотків на залишок
};

#endif // CREDITCARDACCOUNT_H
