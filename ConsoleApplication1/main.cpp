#include "Client.h"

using namespace std;

int main() {
    // 6. Створення 5 об'єктів у статичній пам’яті
    Client staticClients[5] = {
        Client("Yaroslav", 1, 500.0, false, Account(500.0, 200.0, "ACC001")),
        Client("Vova", 2, 300.0, false, Account(300.0, 150.0, "ACC002")),
        Client("Vitalii", 3, 700.0, true, Account(700.0, 350.0, "ACC003")),
        Client("Andtiy", 4, 600.0, false, Account(600.0, 300.0, "ACC004")),
        Client("Taras", 5, 400.0, true, Account(400.0, 250.0, "ACC005"))
    };

    // 6. Створення 5 об'єктів у динамічній пам’яті
    Client* dynamicClients[5];
    for (int i = 0; i < 5; i++) {
        dynamicClients[i] = new Client("Client" + to_string(i + 6), i + 6, 100.0 * (i + 1), false, Account(100.0 * (i + 1), 50.0, "ACC00" + to_string(i + 6)));
    }

    // 8. Продемонструвати роботу з об’єктами, розміщеними в масиві
    staticClients[0].makePayment(100); // Yaroslav здійснює платіж
    staticClients[1].transferTo(staticClients[0], 50); // Vova переказує гроші Yaroslav

    // 9. Продемонструвати роботу усіх методів
    staticClients[0].displayPaymentHistory(); // Відображення історії платежів Yaroslav
    staticClients[1].displayPaymentHistory(); // Відображення історії платежів Vova

    // 10. Сценарій взаємодії двох об’єктів
    staticClients[2].makePayment(200); // Vitalii здійснює платіж
    staticClients[2].transferTo(staticClients[3], 100); // Vitalii переказує гроші Andtiy

    // 11. Використання покажчика на екземпляр класуa
    Client* ptrClient = &staticClients[4]; // Покажчик на Taras
    ptrClient->makePayment(50); // Taras здійснює платіж

    // 12. Додатковий метод для виділення динамічної пам’яті
    vector<int> randomValues;
    for (int i = 0; i < 10; i++) {
        randomValues.push_back(rand() % 100); // Випадкові значення
    }
    sort(randomValues.begin(), randomValues.end()); // Сортування значень

    cout << "Random values sorted: ";
    for (const auto& value : randomValues) {
        cout << value << " "; // Вивід відсортованих значень
    }
    cout << endl;

    // 13. Вивільнення динамічної пам’яті
    for (int i = 0; i < 5; i++) {
        delete dynamicClients[i]; // Вивільняємо пам’ять
    }

    // Додатково: Збереження даних у файли
    for (int i = 0; i < 5; i++) {
        staticClients[i].saveToFile("Client_" + to_string(staticClients[i].getClientID()) + ".txt"); // Запис даних клієнтів
    }

    return 0; // Успішне завершення програми
}
