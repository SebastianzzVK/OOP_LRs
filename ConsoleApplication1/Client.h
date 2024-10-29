#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

class Client {
private:
    string name; // Поле даних для імені клієнта
    int clientID; // Поле даних для ID клієнта
    Account clientAccount; // Поле даних для рахунку клієнта

public:
    Client(); // 1. Конструктор без параметрів
    Client(string name, int clientID, const Account& account); // 1. Конструктор з параметрами
    Client(const Client& other); // 1. Конструктор копіювання

    void makePayment(double amount); // Метод для здійснення платежу
    void displayAccountDetails() const; // Метод для відображення деталей рахунку
};

// Функція для обчислення та виведення інформації про клієнта (п. 5)
void displayClientInfo(const Client& client);
void displayClientInfo(Client* client); // Перевантажена функція (п. 6)

#endif // CLIENT_H
