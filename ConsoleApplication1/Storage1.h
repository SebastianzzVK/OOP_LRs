#ifndef STORAGE1_H
#define STORAGE1_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

template <typename T1, typename T2, typename T3, typename T4, typename T5>
class Storage1 {
private:
    vector<T1> values1;
    vector<T2> values2;
    vector<T3> values3;
    vector<T4> values4;
    vector<T5> values5;

public:
    // ����������� �� �������������
    Storage1() {}

    // ����� ��� ��������� ������ ��������
    template <typename T>
    void addValue(vector<T>& storage, const T& newValue) {
        storage.push_back(newValue);
    }

    // ����� ��� ��������� �������� �� ��������
    template <typename T>
    T getValue(const vector<T>& storage, size_t index) const {
        if (index < storage.size()) {
            return storage[index];
        }
        else {
            throw out_of_range("������ �������� �� ���!");
        }
    }

    // ����� ��� ���������� �������
    template <typename T>
    void sortValues(vector<T>& storage) {
        sort(storage.begin(), storage.end());
    }

    // ����� ��� ��������� �������
    template <typename T>
    void printValues(const vector<T>& storage) const {
        for (const auto& value : storage) {
            cout << value << " ";
        }
        cout << endl;
    }
};

#endif
