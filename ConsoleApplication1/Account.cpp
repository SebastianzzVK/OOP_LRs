#include "Account.h"

// 1. ��������� ������������ ��� ���������
Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("") {}

// 1. ��������� ������������ � �����������
Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {}

void Account::deposit(double amount) {
    // 4. ����� ��� �������� ������
    balance += amount; // ������ ���� �� �������
    transactions.push_back(amount); // ������ ���������� �� �����
    cout << "Deposited: $" << amount << " to account: " << accountNumber << endl;
}

bool Account::withdraw(double amount) {
    // 4. ����� ��� ������ ������
    if (balance + creditLimit >= amount) {
        balance -= amount; // �������� ������
        transactions.push_back(-amount); // ������ ���������� �� �����
        cout << "Withdrew: $" << amount << " from account: " << accountNumber << endl;
        return true; // �������� ������
    }
    else {
        cout << "Insufficient funds for withdrawal from account: " << accountNumber << endl;
        return false; // �������� �� �������
    }
}

double Account::getBalance() const {
    // 4. ����� ��� ��������� �������
    return balance; // ������� ������ �������
}

void Account::saveToFile(const string& filename) const {
    // 5. ����� ��� ������ ����� ������� � ����
    ofstream file(filename);
    if (file.is_open()) {
        file << balance << "\n" << creditLimit << "\n" << accountNumber << "\n";
        file.close();
    }
    else {
        cout << "Failed to open file for writing: " << filename << endl;
    }
}

void Account::loadFromFile(const string& filename) {
    // 5. ����� ��� ������� ����� ������� � �����
    ifstream file(filename);
    if (file.is_open()) {
        file >> balance >> creditLimit >> accountNumber;
        file.close();
    }
    else {
        cout << "Failed to open file for reading: " << filename << endl;
    }
}

void Account::displayTransactionHistory() const {
    // 4. ����� ��� ����������� ����� ����������
    cout << "Transaction history for account " << accountNumber << ":" << endl;
    for (const auto& transaction : transactions) {
        cout << (transaction > 0 ? "Deposited: $" : "Withdrew: $") << abs(transaction) << endl;
    }
}
