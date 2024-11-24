#ifndef PAYMENT6_H
#define PAYMENT6_H

#include <iostream>
#include <string>

using namespace std;

class Payment6 {
private:
    double amount;  // ���� �������
    string date;    // ���� �������
    string type;    // ��� ������� (���������, "�����������", "�������")
    bool isSuccess; // ������ �������: ������� �� �

public:
    // �����������
    Payment6(double amount, const string& date, const string& type, bool isSuccess)
        : amount(amount), date(date), type(type), isSuccess(isSuccess) {}

    // �������
    double getAmount() const { return amount; }
    string getDate() const { return date; }
    string getType() const { return type; }
    bool getIsSuccess() const { return isSuccess; }

    // ��������� ���������� ��� �����
    void display() const {
        cout << "�����: " << type << ", ����: " << amount
            << ", ����: " << date
            << ", ������: " << (isSuccess ? "������" : "��������") << endl;
    }
};

#endif
