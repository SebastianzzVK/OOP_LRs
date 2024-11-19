#ifndef CLIENT_H
#define CLIENT_H

#include "Account.h"

class Client {
private:
    string name;
    int clientID;
    Account clientAccount;

    double creditLimitRequest; // Запит на зміну кредитного ліміту
    bool creditLimitApproved; // Статус затвердження запиту на ліміт

    //Пункт 7
public:
    Client();
    Client(const string& name, int clientID, const Account& account);
    ~Client();


    void displayAccountDetails() const; 

    Client(const std::string& client_name, Account& client_account)
        : name(client_name), clientAccount(client_account) {}

    void show_balance() {
        clientAccount.display_balance();
    }

    void deposit_money(double amount) {
        clientAccount.deposit(amount);
        std::cout << name << " поповнив акаунт на суму: " << amount << std::endl;
    }

    void make_payment(double amount) {
        if (clientAccount.withdraw(amount)) {
            std::cout << name << " здійснив платіж на суму: " << amount << std::endl;
        }
    }
};
#endif 