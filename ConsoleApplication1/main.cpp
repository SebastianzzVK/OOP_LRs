#include "Client.h"

Client processClient(Client client) {
    // ³��������� ���������� ��� �볺���
    client.displayAccountDetails(); // ���� ���������� ��� ������ �볺���

    // ��������� ��� �� ��'���
    return client;
}

int main() {
    // 8. ���������������� ��� ������� ��������� ��'����
    Client client1; // �������
    Client client2("Yaroslav", 1, Account(1000.0, 200.0, "ACC001")); // �����
    Client client3(client2); // ���������� (���������)

    // 10. ���������������� ������ ��� ������������
    cout << "Total Accounts: " << Account::getAccountCount() << endl; // �������� ������� �������
    client1.displayAccountDetails();
    client2.displayAccountDetails();
    client3.displayAccountDetails();

    // 5. ������ ������� ��� ���������� �� ��������� ����������
    displayClientInfo(client2);

    // 6. ������ ������������� �������
    displayClientInfo(&client2);

    //7. ���������� ������� ���� ��������� �����, ��� ����������� ��'��� �����
    Client client4 = processClient(client2);

    // 9. ���������� ��������� �� ��������� �����
    Client* clientPtr = new Client("Vova", 2, Account(1500.0, 300.0, "ACC002")); // �������� ���'���
    clientPtr->displayAccountDetails(); // ������������ ���������� ��'����
    delete clientPtr; // �������� ���������� ��'����

    return 0;
}
