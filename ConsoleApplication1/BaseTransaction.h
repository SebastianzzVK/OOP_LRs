#ifndef BASETRANSACTION_H
#define BASETRANSACTION_H

#include <iostream>
#include <string>
using namespace std;

// ������� ���� ��� ����������
class BaseTransaction {
protected:
    string transactionType; // ��� ����������

private:
    string type;

public:
     

    virtual void logTransaction() const {
        cout << "Transaction Type: " << transactionType << endl;
    }

    explicit BaseTransaction(const string& transactionType)
        : type(transactionType) {}

    virtual ~BaseTransaction() {
        cout << "BaseTransaction destructor called for type: " << type << endl;
    }
};

#endif // BASETRANSACTION_H
