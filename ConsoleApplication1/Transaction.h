#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "BaseTransaction.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdexcept>

// ����������� ���� Transaction �� ���������� ������������
class Transaction : public virtual BaseTransaction {
protected:
    std::string id;
    double amount;        // ���� ����������

public:
    string TransactionId;; // ��������� ������������� ����������
    Transaction(const string& id, double amount, const string& type)
        : BaseTransaction(type), TransactionId(id), amount(amount) {}

    virtual ~Transaction() {
        cout << "Transaction destructor called for ID: " << TransactionId << endl;
    }

    virtual void execute() = 0; // ����������� ����� ��� ��������� ����������

    void displayDetails() const {
        cout << "Transaction ID: " << TransactionId
            << ", Amount: $" << amount << endl;
        logTransaction();
    }
    virtual void displayTransactionDetails() const = 0;  // ����� ���������� �����
   
    
    // ����� ��� ������ � ����
    void Write(const std::string& filename) const {
        try {
            std::ofstream outFile(filename, std::ios::app);  // ³�������� ���� ��� ���������
            if (!outFile) {
                throw std::ios_base::failure("Failed to open file for writing");
            }
            outFile << id << " " << amount << "\n";
            outFile.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception during write operation: " << e.what() << std::endl;
        }
    }

    // ����� ��� ������� � �����
    void Read(const std::string& filename) {
        try {
            std::ifstream inFile(filename);
            if (!inFile) {
                throw std::ios_base::failure("Failed to open file for reading");
            }
            inFile >> id >> amount;  // ������� id � amount
            if (inFile.fail()) {
                throw std::runtime_error("Failed to read data from file");
            }
            inFile.close();
        }
        catch (const std::exception& e) {
            std::cerr << "Exception during read operation: " << e.what() << std::endl;
        }
    }

    void display() const {
        std::cout << "Transaction ID: " << id << ", Amount: " << amount << std::endl;
    }

    
  
};

#endif // TRANSACTION_H
