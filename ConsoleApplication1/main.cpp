#include "Client.h"
#include "Payment.h"
#include "CreditCardAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
#include "DepositTransaction.h"
#include "WithdrawTransaction.h"
#include "TransferTransaction.h"
#include <cstdio>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#pragma execution_character_set( "utf-8" )

Client processClient(Client client) {
    
    client.displayAccountDetails(); 
    return client;
}

// ����� ��� ��������� ��'���� � ���������� ������
void Service_Static(Transaction* transactions[], int& size, const std::string& idToRemove) {
    bool found = false;
    for (int i = 0; i < size; ++i) {
        if (transactions[i]->TransactionId == idToRemove) {
            delete transactions[i];  // ��������� ��'����
            // ���� �������� ����
            for (int j = i; j < size - 1; ++j) {
                transactions[j] = transactions[j + 1];  // ���������� ��������
            }
            transactions[size - 1] = nullptr; // �������� ���������� �������� (�� ��� �� �������)
            --size;  // ��������� ������ ������
            found = true;
            break;
        }
    }
}

void Service_Static(std::vector<std::shared_ptr<Transaction>>& transactions, const std::string& idToRemove) {
    auto it = std::find_if(transactions.begin(), transactions.end(), [&idToRemove](const std::shared_ptr<Transaction>& transaction) {
        return transaction->TransactionId == idToRemove;
        });

    if (it != transactions.end()) {
        transactions.erase(it);
        std::cout << "Transaction with ID " << idToRemove << " removed successfully.\n";
    }
    else {
        std::cerr << "Error: Transaction with ID " << idToRemove << " not found.\n";
    }
}

// ����� ��� ��������� ��'���� � ���������� ������
void Service_Dynamic(std::vector<Transaction*>& transactions, const std::string& idToRemove) {
    try {
        bool found = false;
        for (size_t i = 0; i < transactions.size(); ++i) {
            if (transactions[i]->TransactionId == idToRemove) {
                delete transactions[i];  // ��������� ��'����
                transactions.erase(transactions.begin() + i);  // ��������� � �������
                found = true;
                break;
            }
        }
        if (!found) {
            throw std::runtime_error("Transaction not found for dynamic array.");
        }
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation error: " << e.what() << std::endl;
    }
}

// ������� Service
void Service(Transaction& transaction, const std::string& filename) {
    try {
        // �������� ��� � ����
        transaction.Write(filename);

        // ������� ��� � �����
        transaction.Read(filename);

        // �������� ������ ���
        transaction.display();
    }
    catch (const std::ios_base::failure& e) {
        std::cerr << "I/O Exception in Service: " << e.what() << std::endl;
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory Allocation Failure in Service: " << e.what() << std::endl;
    }
    catch (const std::invalid_argument& e) {
        std::cerr << "Invalid Argument Error in Service: " << e.what() << std::endl;
    }
    catch (const std::runtime_error& e) {
        std::cerr << "Runtime Error in Service: " << e.what() << std::endl;
    }
    catch (...) {
        std::cerr << "An unexpected error occurred in Service." << std::endl;
    }
}

void demonstratePolymorphismUsingPointer(std::vector<std::shared_ptr<Transaction>>& transactions) {
    std::cout << "Polymorphism through pointer:\n";
    for (const auto& transaction : transactions) {
        transaction->display();  // ������ ����������� ������ ����� ��������
    }
}

void demonstratePolymorphismUsingReference(std::vector<std::shared_ptr<Transaction>>& transactions) {
    std::cout << "Polymorphism through reference:\n";
    for (const auto& transaction : transactions) {
        const Transaction& ref = *transaction;
        ref.display();  // ������ ����������� ������ ����� ���������
    }
}

void demonstrateChangingObjectType(std::vector<std::shared_ptr<Transaction>>& transactions) {
    std::cout << "Changing object type using polymorphism:\n";
    for (auto& transaction : transactions) {
        if (DepositTransaction* deposit = dynamic_cast<DepositTransaction*>(transaction.get())) {
            deposit->display();  // ������ ������ ����������� ��� DepositTransaction
        }
        else if (WithdrawTransaction* withdraw = dynamic_cast<WithdrawTransaction*>(transaction.get())) {
            withdraw->display();  // ������ ������ ����������� ��� WithdrawTransaction
        }
    }
}

// ������� ��� ������� ������ ����� ����� ��������� �������
void bypassVirtualMethod(const std::vector<Transaction*>& transactions) {
    std::cout << "Bypassing virtual function call:\n";

    for (const auto& transaction : transactions) {
        // ��������� ����� 'display' ��� ������������ ������������ �����������
        void (Transaction:: * method_ptr)() const = &Transaction::display;
        (transaction->*method_ptr)();  // ��������� ����� ����� �������� �� �������
    }
}

int main(int argc, char* argv[]) {
    SetConsoleOutputCP(CP_UTF8);
    /*Client client1;
    Client client2("Yaroslav", 1, Account(1000.0, 200.0, "ACC001"));
    Client client3(client2);


    cout << "Total Accounts: " << Account::getAccountCount() << endl;
    client1.displayAccountDetails();
    client2.displayAccountDetails();
    client3.displayAccountDetails();


    Client client4 = processClient(client3);


    Client* clientPtr = new Client("Vova", 2, Account(1500.0, 300.0, "ACC002"));
    clientPtr->displayAccountDetails();
    delete clientPtr;


    Account account(1, 1, "string");

    Payment payment1(500.0, "Credit Card");
    payment1.displayPaymentInfo();
    payment1.makePayment();

    CreditCardAccount ccAccount(500.0, 1000.0, "CC001", 3.5);
    SavingsAccount savingsAccount(2000.0, 0.0, "SAV001");
    BusinessAccount businessAccount(10000.0, 5000.0, "BUS001", 2000.0);

    ccAccount.applyInterest();
    cout << "Credit Card Account Balance after interest: $" << ccAccount.getBalance() << endl;

    savingsAccount.addMonthlyInterest();
    cout << "Savings Account Balance after monthly interest: $" << savingsAccount.getBalance() << endl;

    if (businessAccount.overdraft(3000.0)) {
        cout << "Business Account used overdraft. New Balance: $" << businessAccount.getBalance() << endl;
    }
    else {
        cout << "Business Account overdraft failed." << endl;
    }

    cout << "=== Creating objects with simple inheritance ===" << endl;
    {
        Account acc;
        Client client("Yaroslav", 1, acc);
        BusinessAccount businessAcc(1000.0, 500.0, "ACC003", 300.0);
        SavingsAccount savingsAcc(2000.0, 800.0, "ACC004", 2.5);
    }

    cout << "\n=== Creating objects with multiple inheritance ===" << endl;
    {
        CreditCardAccount creditAcc(1500.0, 600.0, "ACC005", 1000.0);
    }

    cout << "\n=== End of main ===" << endl;

    BusinessAccount business_acc(1000.0, "BUS12345", 500.0);
    SavingsAccount savings_acc(5000.0, "SAV67890", 0.03);
    CreditCardAccount credit_card_acc(0.0, "CC12345", 2000.0);

    Client client11("���������", business_acc);
    Client client22("�����", savings_acc);
    Client client33("�����", credit_card_acc);


    client11.show_balance();
    client11.deposit_money(500.0);
    client11.make_payment(2000.0);

    client22.show_balance();
    client22.deposit_money(1000.0);
    client22.make_payment(2000.0);

    client33.show_balance();
    client33.deposit_money(1000.0);
    client33.make_payment(1500.0);

    client11.make_payment(2000.0);
    client33.make_payment(3000.0);
        */

        //1.   Transaction - ����������� ���� 
        //DepositTransaction � ��� ���������� �������.
        //WithdrawTransaction � ��� ������ ����� �� �������.
        //TransferTransaction � ��� �������� ����� �� ���������.
         // ��������� �������
    Account account1(1000.0, "ACC100000000001");
    Account account2(2000.0, "ACC200000000002");

    // ������������ DepositTransaction
    DepositTransaction deposit("TXN001", 500.0, account1);
    deposit.displayDetails();
    deposit.execute();
    account1.display_balance();

    // ������������ WithdrawTransaction
    WithdrawTransaction withdraw("TXN002", 300.0, account1);
    withdraw.displayDetails();
    withdraw.execute();
    account1.display_balance();

    // ������������ TransferTransaction
    TransferTransaction transfer("TXN003", 700.0, account1, account2);
    transfer.displayDetails();
    transfer.execute();
    account1.display_balance();
    account2.display_balance();




    //3. ������������ ���������� �����������
    //���������� ���������� ��������� ��������� ���������� ����������� �������� ����� �� ��� ��������� ��'���� 
    //����� ������� ��������, � ��������� ���������� ������� ����� ���������� �������� �����, ��������� ������.
    /*BaseTransaction destructor called for type: Withdraw
    BaseTransaction destructor called for type : Deposit
    BaseTransaction destructor called for type : Transfer*/

    Account fromAccount(1000, "FromAccount");
    Account toAccount(500, "ToAccount");
    Account testAccount(300, "TestAccount");

    // ����������: ��������� ��'���� ����� ������� ��������
    BaseTransaction* transactions[] = {
        new WithdrawTransaction("1", 100, testAccount),
        new DepositTransaction("2", 200, testAccount),
        new TransferTransaction("3", 50, fromAccount, toAccount)
    };

    // ��������� ��'���� ����� ������� ��������
    for (BaseTransaction* transaction : transactions) {
        delete transaction;
    }

    //4. WithdrawTransaction DepositTransaction TransferTransaction ���������



    Account account3(9990.0, "ACC100000000003");
    Account account4(8000.0, "ACC200000000004");
    //5.

    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////// " << endl;
    try {
        // ��������� 5 ��������� ��'���� ��� ������� ���� ����������
        DepositTransaction deposit1("D1", 500.0, account1);
        WithdrawTransaction withdraw1("W1", 200.0, account2);
        TransferTransaction transfer1("T1", 300.0, account1, account2);

        DepositTransaction deposit2("D2", 1000.0, account2);
        WithdrawTransaction withdraw2("W2", 400.0, account2);

        // ��������� 5 ��������� ��'���� ��� ������� ���� ����������
        DepositTransaction* dynamicDeposit1 = new DepositTransaction("D3", 600.0, account3);
        WithdrawTransaction* dynamicWithdraw1 = new WithdrawTransaction("W3", 150.0, account3);
        TransferTransaction* dynamicTransfer1 = new TransferTransaction("T2", 500.0, account3, account4);

        DepositTransaction* dynamicDeposit2 = new DepositTransaction("D4", 800.0, account4);
        WithdrawTransaction* dynamicWithdraw2 = new WithdrawTransaction("W4", 200.0, account4);

        // ������������ ������ � ��'������
        deposit1.displayTransactionDetails();
        withdraw1.displayTransactionDetails();
        transfer1.displayTransactionDetails();
        deposit2.displayTransactionDetails();
        withdraw2.displayTransactionDetails();

        // ������������ ������ � ���������� ��'������
        dynamicDeposit1->displayTransactionDetails();
        dynamicWithdraw1->displayTransactionDetails();
        dynamicTransfer1->displayTransactionDetails();
        dynamicDeposit2->displayTransactionDetails();
        dynamicWithdraw2->displayTransactionDetails();

        // �������� ��������� ��'����
        delete dynamicDeposit1;
        delete dynamicWithdraw1;
        delete dynamicTransfer1;
        delete dynamicDeposit2;
        delete dynamicWithdraw2;

    }
    catch (const bad_alloc& e) {
        cout << "Exception caught: " << e.what() << endl;
    }
    catch (const runtime_error& e) {
        cout << "Runtime error: " << e.what() << endl;
    }
    catch (const exception& e) {
        cout << "General exception caught: " << e.what() << endl;
    }
    catch (...) {
        cout << "Unknown exception caught!" << endl;
    }
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////// " << endl;
    cout << " " << endl;







    //����� 6
    cout << "����� 6 ////////////////////////////////////////////////////////////////////////////////////////////////////////// " << endl;
    try {
        // ������� ������ (��� ������������)
        const int MAX_SIZE = 5;
        Transaction* transactions[MAX_SIZE];
        int size = 0;

        // ��������� ������ ����������
        transactions[size++] = new DepositTransaction("1", 1000.0, account1);
        transactions[size++] = new DepositTransaction("2", 500.0, account2);

        // ��������� ��� ����������
        for (int i = 0; i < size; ++i) {
            transactions[i]->displayTransactionDetails();
        }

        // ������ ������ ��� ��������� ���������� � ���������� ������
        std::cout << "\nDeleting transaction with ID 1...\n";
        Service_Static(transactions, size, "1");

        // ��������� ���������� ����������
        std::cout << "\nRemaining transactions in static array:\n";
        for (int i = 0; i < size; ++i) {
            transactions[i]->displayTransactionDetails();
        }

        // ������� ������ (������������� std::vector)
        std::vector<Transaction*> dynamicTransactions;
        dynamicTransactions.push_back(new DepositTransaction("3", 2000.0, account3));
        dynamicTransactions.push_back(new DepositTransaction("4", 1500.0, account4));

        // ��������� ��� ����������
        std::cout << "\nDisplaying dynamic transactions:\n";
        for (auto& transaction : dynamicTransactions) {
            transaction->displayTransactionDetails();
        }

        // ������ ������ ��� ��������� ���������� � ���������� ������
        std::cout << "\nDeleting transaction with ID 3...\n";
        Service_Dynamic(dynamicTransactions, "3");

        // ��������� ���������� ����������
        std::cout << "\nRemaining transactions in dynamic array:\n";
        for (auto& transaction : dynamicTransactions) {
            transaction->displayTransactionDetails();
        }

        // ������� ���'�� ��� ��������� ��'����
        for (auto& transaction : dynamicTransactions) {
            delete transaction;
        }
    }
    catch (const std::bad_alloc& e) {
        std::cerr << "Memory allocation failed: " << e.what() << std::endl;
    }
    cout << "////////////////////////////////////////////////////////////////////////////////////////////////////////// " << endl;
    cout << " " << endl;

    //����� 7.
    
    std::string filename = "dsada";

    // ��������� ��'��� ����������
    DepositTransaction transaction("TX12345", 1000.50, account1);

    // ��������� ������� Service
    Service(transaction, filename);




    //����� 8
    std::vector<std::shared_ptr<Transaction>> transactions1;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Create Deposit Transaction\n";
        std::cout << "2. Create Withdraw Transaction\n";
        std::cout << "3. Display Transactions\n";
        std::cout << "4. Remove Transaction\n";
        std::cout << "5. Exit\n";
        std::cout << "Enter your choice: ";

        int choice;
        std::cin >> choice;

        try {
            switch (choice) {
            case 1: {
                std::string id;
                double amount;
                std::cout << "Enter transaction ID: ";
                std::cin >> id;
                std::cout << "Enter amount: ";
                std::cin >> amount;

                transactions1.push_back(std::make_shared<DepositTransaction>(id, amount, account1));
                std::cout << "Deposit Transaction created successfully.\n";
                break;
            }
            case 2: {
                std::string id;
                double amount;
                std::cout << "Enter transaction ID: ";
                std::cin >> id;
                std::cout << "Enter amount: ";
                std::cin >> amount;

                transactions1.push_back(std::make_shared<WithdrawTransaction>(id, amount, account1));
                std::cout << "Withdraw Transaction created successfully.\n";
                break;
            }
            case 3: {
                if (transactions1.empty()) {
                    std::cout << "No transactions available.\n";
                }
                else {
                    for (const auto& transaction : transactions1) {
                        transaction->display();
                    }
                }
                break;
            }
            case 4: {
                std::string idToRemove;
                std::cout << "Enter the ID of the transaction to remove: ";
                std::cin >> idToRemove;

                Service_Static(transactions1, idToRemove);
                break;
            }
            case 5:
                std::cout << "Exiting program...\n";
                return 0;
            default:
                std::cerr << "Invalid choice. Please try again.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    //����� 9
    std::vector<std::shared_ptr<Transaction>> transactions2;

    // ��������� ��'���� ����������
    transactions2.push_back(std::make_shared<DepositTransaction>("D123", 1000.0, account2));
    transactions2.push_back(std::make_shared<WithdrawTransaction>("W456", 500.0, account2));

    // ������������ ����������� ����� ���������
    demonstratePolymorphismUsingPointer(transactions2);

    // ������������ ����������� ����� ���������
    demonstratePolymorphismUsingReference(transactions2);

    // ������������ ���� ����� ��'����
    demonstrateChangingObjectType(transactions2);


    //����� 10
    DepositTransaction deposit14("D123", 500.0, account1);
    deposit14.display();  

    Transaction* transaction14;
    transaction14 = new DepositTransaction("D1233", 5000.0, account1);
    //����� ���������� �� �� ��� ��������� ������ ����쳺 ���� ��� ��'���� � ��� �� ���� �������� �������� �� ����������� ��'���, � �������� ��'��� ������� ����
    delete transaction14;
    transaction14 = new WithdrawTransaction("D12334", 5500.0, account1);
    delete transaction14;


    //����� 11
    std::vector<Transaction*> transactions3;

    // ��������� ��'���� ����� ����
    transactions3.push_back(new DepositTransaction("D123", 1000.0, account2));
    transactions3.push_back(new WithdrawTransaction("W456", 500.0, account2));

    // ������������ ������ ���������� �������
    bypassVirtualMethod(transactions3);

    // �������� ���'��
    for (auto& transaction : transactions3) {
        delete transaction;
    }
    //����� �� �� ���� ����� ��� ���������� ������� �����, ���� ������� ����� �� �����������, � ����� �������

    return 0;
}

