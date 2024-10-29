#include "Client.h"

// 1. ����������� ��� ���������
Client::Client() : name("Unknown"), clientID(0), clientAccount() {}

// 1. ����������� � �����������
Client::Client(string name, int clientID, const Account& account)
    : name(name), clientID(clientID), clientAccount(account) {}

// 1. ����������� ���������
Client::Client(const Client& other)
    : name(other.name), clientID(other.clientID), clientAccount(other.clientAccount) {}

// ����� ��� ��������� �������
void Client::makePayment(double amount) {
    if (clientAccount.withdraw(amount)) {
        cout << name << " made a payment of $" << amount << endl;
    }
    else {
        cout << "Insufficient funds for " << name << endl;
    }
}

// ����� ��� ����������� ������� �������
void Client::displayAccountDetails() const {
    cout << "Client Name: " << name << ", ID: " << clientID << ", Balance: $" << clientAccount.getBalance() << endl;
}

// ������� ��� ���������� �� ��������� ���������� ��� �볺��� (�. 5)
void displayClientInfo(const Client& client) {
    cout << "Client Info: " << endl;
    client.displayAccountDetails();
}

// ������������� ������� (�. 6)
void displayClientInfo(Client* client) {
    if (client) {
        cout << "Client Info (Pointer): " << endl;
        client->displayAccountDetails();
    }
}
