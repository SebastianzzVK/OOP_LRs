#include "Client.h"

Client::Client() : name("Unknown"), clientID(0), clientAccount() {
    cout << "Client default constructor called." << endl;
}

Client::Client(const string& name, int clientID, const Account& account)
    : name(name), clientID(clientID), clientAccount(account) {
    cout << "Client parameterized constructor called." << endl;
}

Client::~Client() {
    cout << "Client destructor called." << endl;
}

void Client::displayAccountDetails() const {
    cout << "Client Name: " << name << ", ID: " << clientID << ", Balance: $" << clientAccount.getBalance() << endl;
}




