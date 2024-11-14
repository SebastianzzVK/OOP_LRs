#include "Client.h"

// 1. Конструктор без параметрів
Client::Client() : name("Unknown"), clientID(0), clientAccount() {
    cout << "Client default constructor called." << endl;
}

// 1. Конструктор з параметрами
Client::Client(const string& name, int clientID, const Account& account)
    : name(name), clientID(clientID), clientAccount(account) {
    cout << "Client parameterized constructor called." << endl;
}


//// Метод для здійснення платежу
//void Client::makePayment(double amount) {
//    if (clientAccount.withdraw(amount)) {
//        cout << name << " made a payment of $" << amount << endl;
//    }
//    else {
//        cout << "Insufficient funds for " << name << endl;
//    }
//}

// Реалізація деструктора
Client::~Client() {
    cout << "Client destructor called." << endl;
}

// Метод для відображення деталей рахунку
void Client::displayAccountDetails() const {
    cout << "Client Name: " << name << ", ID: " << clientID << ", Balance: $" << clientAccount.getBalance() << endl;
}




