#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

class Client {
private:
    string name; // ���� ����� ��� ���� �볺���
    int clientID; // ���� ����� ��� ID �볺���
    Account clientAccount; // ���� ����� ��� ������� �볺���

public:
    Client(); // 1. ����������� ��� ���������
    Client(string name, int clientID, const Account& account); // 1. ����������� � �����������
    Client(const Client& other); // 1. ����������� ���������

    void makePayment(double amount); // ����� ��� ��������� �������
    void displayAccountDetails() const; // ����� ��� ����������� ������� �������
};

// ������� ��� ���������� �� ��������� ���������� ��� �볺��� (�. 5)
void displayClientInfo(const Client& client);
void displayClientInfo(Client* client); // ������������� ������� (�. 6)

#endif // CLIENT_H
