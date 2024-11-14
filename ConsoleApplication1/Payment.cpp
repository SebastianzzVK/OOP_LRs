#include "Payment.h"

// Використання конструктора та методів з класу Client
void Payment::makePayment() {
    
    cout << "Payment of $" << paymentAmount << " completed successfully using " << paymentMethod << endl;
}

void Payment::displayPaymentInfo() const {
    cout << "Payment Method: " << paymentMethod << ", Amount: $" << paymentAmount << endl;
    
}
