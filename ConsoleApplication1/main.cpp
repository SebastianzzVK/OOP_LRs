#include "Client.h"

using namespace std;

int main() {
    // 6. ��������� 5 ��'���� � �������� �����
    Client staticClients[5] = {
        Client("Yaroslav", 1, 500.0, false, Account(500.0, 200.0, "ACC001")),
        Client("Vova", 2, 300.0, false, Account(300.0, 150.0, "ACC002")),
        Client("Vitalii", 3, 700.0, true, Account(700.0, 350.0, "ACC003")),
        Client("Andtiy", 4, 600.0, false, Account(600.0, 300.0, "ACC004")),
        Client("Taras", 5, 400.0, true, Account(400.0, 250.0, "ACC005"))
    };

    // 6. ��������� 5 ��'���� � �������� �����
    Client* dynamicClients[5];
    for (int i = 0; i < 5; i++) {
        dynamicClients[i] = new Client("Client" + to_string(i + 6), i + 6, 100.0 * (i + 1), false, Account(100.0 * (i + 1), 50.0, "ACC00" + to_string(i + 6)));
    }

    // 8. ���������������� ������ � �ᒺ�����, ���������� � �����
    staticClients[0].makePayment(100); // Yaroslav ������� �����
    staticClients[1].transferTo(staticClients[0], 50); // Vova �������� ����� Yaroslav

    // 9. ���������������� ������ ��� ������
    staticClients[0].displayPaymentHistory(); // ³���������� ����� ������� Yaroslav
    staticClients[1].displayPaymentHistory(); // ³���������� ����� ������� Vova

    // 10. ������� �����䳿 ���� �ᒺ���
    staticClients[2].makePayment(200); // Vitalii ������� �����
    staticClients[2].transferTo(staticClients[3], 100); // Vitalii �������� ����� Andtiy

    // 11. ������������ ��������� �� ��������� �����a
    Client* ptrClient = &staticClients[4]; // �������� �� Taras
    ptrClient->makePayment(50); // Taras ������� �����

    // 12. ���������� ����� ��� �������� �������� �����
    vector<int> randomValues;
    for (int i = 0; i < 10; i++) {
        randomValues.push_back(rand() % 100); // �������� ��������
    }
    sort(randomValues.begin(), randomValues.end()); // ���������� �������

    cout << "Random values sorted: ";
    for (const auto& value : randomValues) {
        cout << value << " "; // ���� ������������ �������
    }
    cout << endl;

    // 13. ���������� �������� �����
    for (int i = 0; i < 5; i++) {
        delete dynamicClients[i]; // ���������� ������
    }

    // ���������: ���������� ����� � �����
    for (int i = 0; i < 5; i++) {
        staticClients[i].saveToFile("Client_" + to_string(staticClients[i].getClientID()) + ".txt"); // ����� ����� �볺���
    }

    return 0; // ������ ���������� ��������
}
