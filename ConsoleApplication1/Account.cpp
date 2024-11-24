#include "Account.h"


int Account::accountCount = 0;


Account::Account() : balance(0.0), creditLimit(0.0), accountNumber("DEFAULT") {
    accountCount++; 
    cout << "Account constructor called." << endl;
    cout << "Account parameterized constructor called." << endl;
    cout << "Account destructor called." << endl;
}


Account::Account(double balance, double creditLimit, const string& accountNumber)
    : balance(balance), creditLimit(creditLimit), accountNumber(accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}


Account::Account(const Account& other)
    : balance(other.balance), creditLimit(other.creditLimit), accountNumber(other.accountNumber) {
    accountCount++;
    cout << "Account created. Account count:" << endl;
}


Account::~Account() {
    accountCount--;
    cout << "Account destroyed. Account count: " << accountCount << endl;
}



double Account::getBalance() const {
    return balance;
}


int Account::getAccountCount() {
    return accountCount;
}
// ���������� �������� ++
Account& Account::operator++() {
    balance += 1.0;
    return *this;
}

// ����������� �������� ++
Account Account::operator++(int) {
    Account temp = *this;
    balance += 1.0;
    return temp;
}

// ���������� �������� --
Account& Account::operator--() {
    if (balance > 0.0) {
        balance -= 1.0;
    }
    return *this;
}

// ����������� �������� --
Account Account::operator--(int) {
    Account temp = *this;
    if (balance > 0.0) {
        balance -= 1.0;
    }
    return temp;
}


// �������������� �������� ��������� +
Account Account::operator+(double amount) const {
    return Account(balance + amount, creditLimit, accountNumber);
}

// �������������� �������� ��������� -
Account Account::operator-(double amount) const {
    if (balance >= amount) {
        return Account(balance - amount, creditLimit, accountNumber);
    }
    else {
        std::cout << "����������� ����� ��� ��������!" << std::endl;
        return *this;
    }
}

// �������� ��������� =
Account& Account::operator=(const Account& other) {
    if (this != &other) {
        balance = other.balance;
        creditLimit = other.creditLimit;
        accountNumber = other.accountNumber;
    }
    return *this;
}

// �������� +=
Account& Account::operator+=(double amount) {
    balance += amount;
    return *this;
}

// �������� -=
Account& Account::operator-=(double amount) {
    if (balance >= amount) {
        balance -= amount;
    }
    else {
        std::cout << "����������� ����� ��� ������!" << std::endl;
    }
    return *this;
}

// �������� *=
Account& Account::operator*=(double factor) {
    balance *= factor;
    return *this;
}

// �������� *
Account Account::operator*(double factor) const {
    return Account(balance * factor, creditLimit, accountNumber);
}

// �������� []
char& Account::operator[](size_t index) {
    if (index >= accountNumber.size()) {
        throw out_of_range("������ �������� �� ��� ������ �������.");
    }
    return accountNumber[index];
}
