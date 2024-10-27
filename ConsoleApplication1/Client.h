#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

using namespace std;

// 1. Визначити 2 будь-яких користувацьких класи: Client та Account
class Client {
private:
    string name;         // Приватне поле для зберігання імені клієнта
    int clientID;       // Приватне поле для зберігання ID клієнта
    double creditLimit;  // Приватне поле для зберігання кредитного ліміту
    bool isVIP;         // Приватне поле для визначення статусу VIP
    Account clientAccount; // 3. Об'єкт класу Account, що представляє рахунок клієнта

public:
    Client(); // Конструктор без параметрів
    Client(string name, int clientID, double creditLimit, bool isVIP, const Account& account); // Конструктор з параметрами

    // 4. Метод для здійснення платежу
    void makePayment(double amount);

    // 4. Метод для переказу грошей іншому клієнту
    void transferTo(Client& otherClient, double amount);

    // 4. Метод для запиту підвищення кредитного ліміту
    void requestCreditLimitIncrease(double newLimit);

    // 5. Метод для запису даних клієнта у файл
    void saveToFile(const string& filename) const;

    // 5. Метод для читання даних клієнта з файлу
    void loadFromFile(const string& filename);

    // 4. Метод для відображення історії платежів
    void displayPaymentHistory() const;

    // 4. Метод для отримання ID клієнта
    int getClientID() const; // Повертає ID клієнта
};

#endif // CLIENT_H
