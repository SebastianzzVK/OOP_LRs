#include "Client.h"

// 1. Конструктор без параметрів
Client::Client() : name("Unknown"), clientID(0), clientAccount() {}

// 1. Конструктор з параметрами
Client::Client(string name, int clientID, const Account& account)
    : name(name), clientID(clientID), clientAccount(account) {}

// 1. Конструктор копіювання
Client::Client(const Client& other)
    : name(other.name), clientID(other.clientID), clientAccount(other.clientAccount) {}

// Метод для здійснення платежу
void Client::makePayment(double amount) {
    if (clientAccount.withdraw(amount)) {
        cout << name << " made a payment of $" << amount << endl;
    }
    else {
        cout << "Insufficient funds for " << name << endl;
    }
}

// Метод для відображення деталей рахунку
void Client::displayAccountDetails() const {
    cout << "Client Name: " << name << ", ID: " << clientID << ", Balance: $" << clientAccount.getBalance() << endl;
}

// Функція для обчислення та виведення інформації про клієнта (п. 5)
void displayClientInfo(const Client& client) {
    cout << "Client Info: " << endl;
    client.displayAccountDetails();
}

// Перевантажена функція (п. 6)
void displayClientInfo(Client* client) {
    if (client) {
        cout << "Client Info (Pointer): " << endl;
        client->displayAccountDetails();
    }
}
