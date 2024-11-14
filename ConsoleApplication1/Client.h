#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

class Client {
private:
    string name;
    int clientID;
    Account clientAccount;

    double creditLimitRequest; // ����� �� ���� ���������� ����
    bool creditLimitApproved; // ������ ������������ ������ �� ���

    //����� 7
public:
    Client();
    Client(const string& name, int clientID, const Account& account);
    ~Client();


    void displayAccountDetails() const; // ����� ��� ����������� ������� �������

    Client(const std::string& client_name, Account& client_account)
        : name(client_name), clientAccount(client_account) {}

    // ����� ��� ������ ������� ������� �볺���
    void show_balance() {
        clientAccount.display_balance();
    }

    // ����� ��� ���������� ������� �볺���
    void deposit_money(double amount) {
        clientAccount.deposit(amount);
        std::cout << name << " �������� ������ �� ����: " << amount << std::endl;
    }

    // ����� ��� ��������� ������� � ������� �볺���
    void make_payment(double amount) {
        if (clientAccount.withdraw(amount)) {
            std::cout << name << " ������� ����� �� ����: " << amount << std::endl;
        }



    }
};
#endif // CLIENT_H