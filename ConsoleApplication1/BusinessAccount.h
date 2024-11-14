#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H

#include "Account.h"
using namespace std;
class BusinessAccount : public Account {
private:
    double overdraftLimit;

public:
    //5 пункт
    // Конструктор приймає параметри для Account та додатковий параметр overdraftLimit
    BusinessAccount(double balance, double creditLimit, const string& accountNumber, double overdraftLimit);
        
    BusinessAccount(double initial_balance, const std::string& acc_number, double overdraft)
        : Account(initial_balance, acc_number), overdraftLimit(overdraft) {}

    // Метод для перевірки можливості використання овердрафту
    bool overdraft(double amount);

    //Пункт 7
    BusinessAccount();
    ~BusinessAccount();



    // 6. Метод, що використовує оператор глобального доступу
    void accessBaseClassMembersGlobal() {
        // Використання оператора глобального доступу для доступу до статичного члена
        cout << "Total Accounts (via global access): " << Account::getAccountCount() << endl;

        // Використання оператора глобального доступу для доступу до метода getBalance
        double balance = Account::getBalance();
        cout << "Balance (via global access): " << balance << endl;
    }


        // 6. Метод, що використовує оператор using
    // Використання оператора using для доступу до методу базового класу deposit
        using Account::deposit;
    
    void accessBaseClassMembersUsing() {
        

        // Виклик методу deposit з базового класу
        deposit(100);
        cout << "Deposit of 100 made using 'using' operator. New Balance: " << getBalance() << endl;
    }
};

#endif // BUSINESSACCOUNT_H
