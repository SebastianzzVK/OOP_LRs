#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Account {
private:
    double balance; // ���� ����� ��� ������� �������
    double creditLimit; // ���� ����� ��� ���������� ����
    string accountNumber; // ���� ����� ��� ������ �������
    static int accountCount; // �������� ���� ��� ��������� �������

public:
    Account(); // 1. ����������� ��� ���������
    Account(double balance, double creditLimit, const string& accountNumber); // 1. ����������� � �����������
    Account(const Account& other); // 1. ����������� ���������

    

    void deposit(double amount); // ����� ��� �������� ������
    bool withdraw(double amount); // ����� ��� ������ ������
    double getBalance() const; // ����� ��� ��������� �������
    static int getAccountCount(); // ��������� ����� ��� ��������� ������� �������
    ~Account(); // 3. ����������
};

#endif // ACCOUNT_H
