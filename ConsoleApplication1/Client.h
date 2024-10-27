#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

using namespace std;

// 1. ��������� 2 ����-���� �������������� �����: Client �� Account
class Client {
private:
    string name;         // �������� ���� ��� ��������� ���� �볺���
    int clientID;       // �������� ���� ��� ��������� ID �볺���
    double creditLimit;  // �������� ���� ��� ��������� ���������� ����
    bool isVIP;         // �������� ���� ��� ���������� ������� VIP
    Account clientAccount; // 3. ��'��� ����� Account, �� ����������� ������� �볺���

public:
    Client(); // ����������� ��� ���������
    Client(string name, int clientID, double creditLimit, bool isVIP, const Account& account); // ����������� � �����������

    // 4. ����� ��� ��������� �������
    void makePayment(double amount);

    // 4. ����� ��� �������� ������ ������ �볺���
    void transferTo(Client& otherClient, double amount);

    // 4. ����� ��� ������ ��������� ���������� ����
    void requestCreditLimitIncrease(double newLimit);

    // 5. ����� ��� ������ ����� �볺��� � ����
    void saveToFile(const string& filename) const;

    // 5. ����� ��� ������� ����� �볺��� � �����
    void loadFromFile(const string& filename);

    // 4. ����� ��� ����������� ����� �������
    void displayPaymentHistory() const;

    // 4. ����� ��� ��������� ID �볺���
    int getClientID() const; // ������� ID �볺���
};

#endif // CLIENT_H
