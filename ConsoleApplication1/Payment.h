#ifndef PAYMENT_H
#define PAYMENT_H

#include "Client.h"

class Payment : private Client { // Закрите наслідування від Client
private:
    double paymentAmount; // Сума платежу
    string paymentMethod; // Метод платежу (наприклад, картка, банківський переказ)

public:
    Payment(double amount, string method)
        : paymentAmount(amount), paymentMethod(method) {} // Конструктор, що використовує конструктор Client

    //Пункт 7
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
