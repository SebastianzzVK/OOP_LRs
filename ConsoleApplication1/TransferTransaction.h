#ifndef TRANSFERTRANSACTION_H
#define TRANSFERTRANSACTION_H

#include "Transaction.h"
#include "Account.h"

class TransferTransaction : public Transaction {
private:
    Account& sourceAccount;
    Account& destinationAccount;
   

public:
    std::string TransactionId;
    TransferTransaction(const string& id, double amount, Account& from, Account& to)
        : Transaction(id, amount, "Transfer"), // Виклик конструктора Transaction
        BaseTransaction("Transfer"),        // Виклик конструктора BaseTransaction
        sourceAccount(from), destinationAccount(to), TransactionId(id) {}

    ~TransferTransaction() override {
        cout << "TransferTransaction destructor called for transfer" << endl;
    }

    //4.
    void execute() override {
        if (sourceAccount.withdraw(amount)) {
            destinationAccount.deposit(amount);
            cout << "TransferTransaction executed. Amount: $" << amount << endl;
        }
        else {
            cout << "TransferTransaction failed." << endl;
        }
    }

    // Метод для виведення деталей транзакції
    void displayTransactionDetails() const {
        std::cout << "Transfer Transaction ID: " << TransactionId << std::endl;
        std::cout << "Amount: " << amount << std::endl;
        std::cout << "From Account: " << sourceAccount.accountHolder << std::endl;
        std::cout << "To Account: " << destinationAccount.accountHolder << std::endl;
    }
};

#endif // TRANSFERTRANSACTION_H
