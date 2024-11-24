#ifndef DEPOSITTRANSACTION_H
#define DEPOSITTRANSACTION_H

#include "Transaction.h"
#include "Account.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class DepositTransaction : public Transaction {
private:
    Account& account;
    std::string accountId;


public:
    std::string TransactionId;
    DepositTransaction(const string& id, double amount, Account& acc)
        : Transaction(id, amount, "Deposit"), // Виклик конструктора Transaction
        BaseTransaction("Deposit"),        // Виклик конструктора BaseTransaction
        account(acc), TransactionId(id) {}
    

    ~DepositTransaction() override {
        cout << "DepositTransaction destructor called for account" << endl;
    }

    //4.
    void execute() override {
        account.deposit(amount);
        cout << "DepositTransaction executed. Amount: $" << amount << endl;
    }

    
    // Метод для виведення деталей транзакції
    void displayTransactionDetails() const {
        std::cout << "Deposit Transaction ID: " << TransactionId << std::endl;
        std::cout << "Amount: " << amount << std::endl;
        std::cout << "Account ID: " << account.accountNumber << std::endl;
    }
};


#endif // DEPOSITTRANSACTION_H
