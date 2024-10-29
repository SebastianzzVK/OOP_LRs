#include "Client.h"

Client processClient(Client client) {
    // Відображаємо інформацію про клієнта
    client.displayAccountDetails(); // Вивід інформації про платежі клієнта

    // Повертаємо той же об'єкт
    return client;
}

int main() {
    // 8. Продемонструвати три способи створення об'єктів
    Client client1; // Простий
    Client client2("Yaroslav", 1, Account(1000.0, 200.0, "ACC001")); // Явний
    Client client3(client2); // Скорочений (копіювання)

    // 10. Продемонструвати роботу усіх конструкторів
    cout << "Total Accounts: " << Account::getAccountCount() << endl; // Показати кількість рахунків
    client1.displayAccountDetails();
    client2.displayAccountDetails();
    client3.displayAccountDetails();

    // 5. Виклик функції для обчислення та виведення інформації
    displayClientInfo(client2);

    // 6. Виклик перевантаженої функції
    displayClientInfo(&client2);

    //7. Оголошення функції типу описаного класу, яка повертатиме об'єкт класу
    Client client4 = processClient(client2);

    // 9. Оголошення покажчика на екземпляр класу
    Client* clientPtr = new Client("Vova", 2, Account(1500.0, 300.0, "ACC002")); // Динамічна пам'ять
    clientPtr->displayAccountDetails(); // Використання динамічного об'єкта
    delete clientPtr; // Очищення динамічного об'єкта

    return 0;
}
