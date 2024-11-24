#ifndef PAYMENT6_H
#define PAYMENT6_H

#include <iostream>
#include <string>

using namespace std;

class Payment6 {
private:
    double amount;  // Сума платежу
    string date;    // Дата платежу
    string type;    // Тип платежу (наприклад, "перерахунок", "покупка")
    bool isSuccess; // Статус платежу: успішний чи ні

public:
    // Конструктор
    Payment6(double amount, const string& date, const string& type, bool isSuccess)
        : amount(amount), date(date), type(type), isSuccess(isSuccess) {}

    // Геттери
    double getAmount() const { return amount; }
    string getDate() const { return date; }
    string getType() const { return type; }
    bool getIsSuccess() const { return isSuccess; }

    // Виведення інформації про платіж
    void display() const {
        cout << "Платіж: " << type << ", сума: " << amount
            << ", дата: " << date
            << ", статус: " << (isSuccess ? "Успішно" : "Неуспішно") << endl;
    }
};

#endif
