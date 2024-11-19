#ifndef WITHDRAWTRANSACTION_H
#define WITHDRAWTRANSACTION_H

#include "Transaction.h"
#include "Account.h"
#include <iostream>
#include <vector>
#include <memory>
#include <stdexcept>

class WithdrawTransaction : public Transaction {
private:
    Account& account;
    std::string accountId;
public:
    std::string TransactionId;
    WithdrawTransaction(const string& id, double amount, Account& acc)
        : Transaction(id, amount, "Withdraw"), // Виклик конструктора Transaction
        BaseTransaction("Withdraw"),        // Виклик конструктора BaseTransaction
        account(acc), TransactionId(id) {}

    ~WithdrawTransaction() override {
        cout << "WithdrawTransaction destructor called for account" << endl;
    }

    //4.
    void execute() override {
        if (account.withdraw(amount)) {
            cout << "WithdrawTransaction executed. Amount: $" << amount << endl;
        }
        else {
            cout << "WithdrawTransaction failed due to insufficient funds." << endl;
        }
    }

 
    // Метод для виведення деталей транзакції
    void displayTransactionDetails() const {
        std::cout << "Withdraw Transaction ID: " << TransactionId << std::endl;
        std::cout << "Amount: " << amount << std::endl;
        std::cout << "Account ID: " << account.accountNumber << std::endl;
    }
};

#endif // WITHDRAWTRANSACTION_H
