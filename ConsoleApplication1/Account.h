#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// 1. ��������� ���� Account
class Account {
private:
    double balance;           // �������� ���� ��� ��������� �������
    double creditLimit;       // �������� ���� ��� ��������� ���������� ����
    string accountNumber;     // �������� ���� ��� ��������� ������ �������
    vector<double> transactions; // �������� ���� ��� ��������� ����� ����������

public:
    Account(); // ����������� ��� ���������
    Account(double balance, double creditLimit, const string& accountNumber); // ����������� � �����������

    // 4. ����� ��� �������� ������
    void deposit(double amount);

    // 4. ����� ��� ������ ������
    bool withdraw(double amount);

    // 4. ����� ��� ��������� �������
    double getBalance() const;

    // 5. ����� ��� ������ ����� ������� � ����
    void saveToFile(const string& filename) const;

    // 5. ����� ��� ������� ����� ������� � �����
    void loadFromFile(const string& filename);

    // 4. ����� ��� ����������� ����� ����������
    void displayTransactionHistory() const;
};

#endif // ACCOUNT_H
