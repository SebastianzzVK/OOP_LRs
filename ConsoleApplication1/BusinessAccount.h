#ifndef BUSINESSACCOUNT_H
#define BUSINESSACCOUNT_H

#include "Account.h"
using namespace std;
class BusinessAccount : public Account {
private:
    double overdraftLimit;

public:
    //5 �����
    // ����������� ������ ��������� ��� Account �� ���������� �������� overdraftLimit
    BusinessAccount(double balance, double creditLimit, const string& accountNumber, double overdraftLimit);
        
    BusinessAccount(double initial_balance, const std::string& acc_number, double overdraft)
        : Account(initial_balance, acc_number), overdraftLimit(overdraft) {}

    // ����� ��� �������� ��������� ������������ ����������
    bool overdraft(double amount);

    //����� 7
    BusinessAccount();
    ~BusinessAccount();



    // 6. �����, �� ����������� �������� ����������� �������
    void accessBaseClassMembersGlobal() {
        // ������������ ��������� ����������� ������� ��� ������� �� ���������� �����
        cout << "Total Accounts (via global access): " << Account::getAccountCount() << endl;

        // ������������ ��������� ����������� ������� ��� ������� �� ������ getBalance
        double balance = Account::getBalance();
        cout << "Balance (via global access): " << balance << endl;
    }


        // 6. �����, �� ����������� �������� using
    // ������������ ��������� using ��� ������� �� ������ �������� ����� deposit
        using Account::deposit;
    
    void accessBaseClassMembersUsing() {
        

        // ������ ������ deposit � �������� �����
        deposit(100);
        cout << "Deposit of 100 made using 'using' operator. New Balance: " << getBalance() << endl;
    }
};

#endif // BUSINESSACCOUNT_H
