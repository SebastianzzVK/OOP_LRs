#ifndef PAYMENT_H
#define PAYMENT_H

#include "Client.h"

class Payment : private Client { // ������� ����������� �� Client
private:
    double paymentAmount; // ���� �������
    string paymentMethod; // ����� ������� (���������, ������, ���������� �������)

public:
    Payment(double amount, string method)
        : paymentAmount(amount), paymentMethod(method) {} // �����������, �� ����������� ����������� Client

    //����� 7
    Payment():paymentAmount(0.0), paymentMethod("def") {
        std::cout << "Payment constructor called." << std::endl;
    }
     ~Payment() {
         std::cout << "Payment destructor called." << std::endl;
    }

    void makePayment();

    void displayPaymentInfo() const; 
};

#endif // PAYMENT_H
