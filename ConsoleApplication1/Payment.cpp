#include "Payment.h"

// ������������ ������������ �� ������ � ����� Client
void Payment::makePayment() {
    
    cout << "Payment of $" << paymentAmount << " completed successfully using " << paymentMethod << endl;
}

void Payment::displayPaymentInfo() const {
    cout << "Payment Method: " << paymentMethod << ", Amount: $" << paymentAmount << endl;
    
}
