#include "Client.h"
#include "Payment.h"
#include "CreditCardAccount.h"
#include "SavingsAccount.h"
#include "BusinessAccount.h"
#include <cstdio>
#include <windows.h>
#pragma execution_character_set( "utf-8" )

Client processClient(Client client) {
    
    client.displayAccountDetails(); 
    return client;
}

int main() {
     SetConsoleOutputCP(CP_UTF8);
    Client client1; // �������
    Client client2("Yaroslav", 1, Account(1000.0, 200.0, "ACC001")); // �����
    Client client3(client2); // ���������� (���������)

   
    cout << "Total Accounts: " << Account::getAccountCount() << endl; // �������� ������� �������
    client1.displayAccountDetails();
    client2.displayAccountDetails();
    client3.displayAccountDetails();

    
    
    
    Client client4 = processClient(client3);

    
    Client* clientPtr = new Client("Vova", 2, Account(1500.0, 300.0, "ACC002")); // �������� ���'���
    clientPtr->displayAccountDetails(); // ������������ ���������� ��'����
    delete clientPtr; // �������� ���������� ��'����

    //2. 
    Account account(1, 1, "string");
    // account.  
    //(�� ������ ��������� ��� 3 ������ �� 2 ������ ����, �� ������ ��������� protected ���� �� ���� ������ ��������� ��� � ������� ����� �� � ������� ������,
    // � private ��� � ����� ����)

    // 3. ��������� ��������� ��'����
    Payment payment1(500.0, "Credit Card"); // ������������� ����������� Payment
    payment1.displayPaymentInfo(); // ��������� ���������� ��� �����
    payment1.makePayment(); // ��������� �������


    //4. ������������ ����������� ���������� �����
    //////////////////////////////////////////////////////
    // 
    // ��������� ��'���� ����� ���� �������, �� ����������� �� Account
    CreditCardAccount ccAccount(500.0, 1000.0, "CC001", 3.5);
    SavingsAccount savingsAccount(2000.0, 0.0, "SAV001");
    BusinessAccount businessAccount(10000.0, 5000.0, "BUS001", 2000.0);

    // ������������ ����� �������, �� ������� ��� ��'����
    ccAccount.applyInterest();
    cout << "Credit Card Account Balance after interest: $" << ccAccount.getBalance() << endl;

    savingsAccount.addMonthlyInterest();
    cout << "Savings Account Balance after monthly interest: $" << savingsAccount.getBalance() << endl;

    if (businessAccount.overdraft(3000.0)) {
        cout << "Business Account used overdraft. New Balance: $" << businessAccount.getBalance() << endl;
    }
    else {
        cout << "Business Account overdraft failed." << endl;
    }
    //////////////////////////////////////////////////////

    //5 ����� BusinessAccount
    //6 ����� BusinessAccount

    // 7/8 �����
    cout << "=== Creating objects with simple inheritance ===" << endl;
    {
        Account acc;
        Client client("Yaroslav", 1, acc);
        BusinessAccount businessAcc(1000.0, 500.0, "ACC003", 300.0);
        SavingsAccount savingsAcc(2000.0, 800.0, "ACC004", 2.5);
    }

    cout << "\n=== Creating objects with multiple inheritance ===" << endl;
    {
        CreditCardAccount creditAcc(1500.0, 600.0, "ACC005", 1000.0);
    }

    cout << "\n=== End of main ===" << endl;




    // ��������� �������
    BusinessAccount business_acc(1000.0, "BUS12345", 500.0);
    SavingsAccount savings_acc(5000.0, "SAV67890", 0.03);
    CreditCardAccount credit_card_acc(0.0, "CC12345", 2000.0);

    // ��������� �볺���
    Client client11("���������", business_acc);
    Client client22("�����", savings_acc);
    Client client33("�����", credit_card_acc);

    // ������������ ��������������� �������
    client11.show_balance(); // ������� ������ �����-�������
    client11.deposit_money(500.0); // ���������� �������
    client11.make_payment(2000.0); // �����

    client22.show_balance(); // ������� ������ ���������������� �������
    client22.deposit_money(1000.0); // ����������
    client22.make_payment(2000.0); // �����

    client33.show_balance(); // ������� ������ ������
    client33.deposit_money(1000.0); // ����������
    client33.make_payment(1500.0); // �����

    
    // ������������ �������� ������� � ������ ������
    client11.make_payment(2000.0); // ����� � �����-�������
    client33.make_payment(3000.0); // ����� � �������� ������

    

    return 0;
}
