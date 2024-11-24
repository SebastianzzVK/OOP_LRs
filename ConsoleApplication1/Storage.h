#ifndef STORAGE_H
#define STORAGE_H

#include <iostream>
#include <vector>
#include <algorithm>
#include "Payment6.h"  // ϳ��������� ����� Payment6

using namespace std;

template <typename T>
class Storage {
private:
    vector<T> values;  // ������ ��� ���������� ��'���� ���� T

public:
    // ����������� �� �������������
    Storage() {}

    // ����� ��� ��������� ������ ��������
    void addValue(const T& newValue) {
        values.push_back(newValue);
    }

    // ����� ��� ���������� �������
    void sortValues() {
        sort(values.begin(), values.end(), [](const T& a, const T& b) {
            return a.getAmount() < b.getAmount();  // ���������� �� ����� �������
            });
    }

    // ����� ��� ��������� �������
    void printValues() const {
        for (const auto& value : values) {
            value.display();
        }
    }
};

#endif
