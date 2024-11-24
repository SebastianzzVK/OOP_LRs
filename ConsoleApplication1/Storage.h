#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Payment6.h"  // Підключення класу Payment6

using namespace std;

template <typename T>
class Storage {
private:
    vector<T> values;  // Вектор для збереження об'єктів типу T

public:
    // Конструктор за замовчуванням
    Storage() {}

    // Метод для додавання нового значення
    void addValue(const T& newValue) {
        values.push_back(newValue);
    }

    // Метод для сортування значень
    void sortValues() {
        sort(values.begin(), values.end(), [](const T& a, const T& b) {
            return a.getAmount() < b.getAmount();  // Сортування за сумою платежу
            });
    }

    // Метод для виведення значень
    void printValues() const {
        for (const auto& value : values) {
            value.display();
        }
    }
};

#endif
