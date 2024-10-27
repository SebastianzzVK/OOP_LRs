#include "Client.h"

// 1. Реалізація конструктора без параметрів
Client::Client() : name(""), clientID(0), creditLimit(0.0), isVIP(false), clientAccount() {}

// 1. Реалізація конструктора з параметрами
Client::Client(string name, int clientID, double creditLimit, bool isVIP, const Account& account)
    : name(name), clientID(clientID), creditLimit(creditLimit), isVIP(isVIP), clientAccount(account) {}

void Client::makePayment(double amount) {
    // 4. Метод для здійснення платежу
    if (clientAccount.withdraw(amount)) {
        cout << name << " made a payment of $" << amount << endl;
    }
    else {
        cout << "Insufficient balance for payment." << endl;
    }
}

void Client::transferTo(Client& otherClient, double amount) {
    // 4. Метод для переказу грошей іншому клієнту
    if (clientAccount.withdraw(amount)) {
        otherClient.clientAccount.deposit(amount);
        cout << name << " transferred $" << amount << " to Client ID: " << otherClient.clientID << endl;
    }
    else {
        cout << "Insufficient balance for transfer." << endl;
    }
}

void Client::requestCreditLimitIncrease(double newLimit) {
    // 4. Метод для запиту підвищення кредитного ліміту
    if (newLimit > creditLimit) creditLimit = newLimit;
}

void Client::saveToFile(const string& filename) const {
    // 5. Метод для запису даних клієнта у файл
    ofstream file(filename);
    if (file.is_open()) {
        file << name << "\n" << clientID << "\n" << creditLimit << "\n" << isVIP << "\n";
        clientAccount.saveToFile(filename + "_account"); // Запис інформації про рахунок
        file.close();
    }
    else {
        cout << "Failed to open file for writing: " << filename << endl;
    }
}

void Client::loadFromFile(const string& filename) {
    // 5. Метод для читання даних клієнта з файлу
    ifstream file(filename);
    if (file.is_open()) {
        file >> name >> clientID >> creditLimit >> isVIP;
        clientAccount.loadFromFile(filename + "_account"); // Читання інформації про рахунок
        file.close();
    }
    else {
        cout << "Failed to open file for reading: " << filename << endl;
    }
}

void Client::displayPaymentHistory() const {
    // 4. Метод для відображення історії платежів
    cout << "Payment history for " << name << ":" << endl;
    clientAccount.displayTransactionHistory();
}

int Client::getClientID() const {
    // 4. Повертає ID клієнта
    return clientID;
}
