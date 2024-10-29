#include "Account.h"

// ����������� ���������� �����
int Account::accountCount = 0;

// 1. ����������� ��� ���������
Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("DEFAULT") {
    accountCount++; // ��������� ��������� �������
}

// 1. ����������� � �����������
Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {
    accountCount++;
}

// 1. ����������� ���������
Account::Account(const Account& other)
    : balance(other.balance), creditLimit(other.creditLimit), accountNumber(other.accountNumber) {
    accountCount++;
}

// 3. ����������
Account::~Account() {
    accountCount--; // ��������� ��������� ������� ��� �������� ��'����
}

// ����� ��� �������� ������
void Account::deposit(double amount) {
    balance += amount;
}

// ����� ��� ������ ������
bool Account::withdraw(double amount) {
    if (balance + creditLimit >= amount) {
        balance -= amount;
        return true;
    }
    return false;
}

// ����� ��� ��������� �������
double Account::getBalance() const {
    return balance;
}

// 4. ��������� ����� ��� ��������� ������� �������
int Account::getAccountCount() {
    return accountCount;
}
