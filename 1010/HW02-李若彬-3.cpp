#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amount;   // ������
    int type;        // ��Ʒ����
    char service;    // ��������

    // �������������Ʒ����ͷ�������
    cout << "Input amount: ";
    cin >> amount;

    cout << "Input type: ";
    cin >> type;

    cout << "Input service: ";
    cin >> service;

    // ��Ʒ�۸�
    double price = 0.0;
    switch (type) {
        case 90:
            price = 5.82;
        break;
        case 93:
            price = 5.96;
        break;
        case 97:
            price = 6.36;
        break;
        case 0:
            price = 5.59;
        break;
        default:
            cout << "Invalid oil type!" << endl;
        return 1;  // �˳�����
    }

    // �ۿۼ���
    double discount = 1.0;
    if (service == 's') {
        discount = 0.95;  // ��������
    } else if (service == 'a') {
        discount = 0.97;  // Э������
    } else {
        cout << "Invalid service type!" << endl;
        return 1;  // �˳�����
    }

    // �����ܽ��
    double total = amount * price * discount;

    // ������������2λС��
    cout << "Output: " << fixed << setprecision(2) << total << endl;

    return 0;
}