#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "������һ��5λ����: ";
    cin >> num;

    // ��ȡ����λ�ϵ�����
    int digit1 = num / 10000;         // ��һλ
    int digit2 = (num / 1000) % 10;   // �ڶ�λ
    int digit4 = (num / 10) % 10;     // ����λ
    int digit5 = num % 10;            // ����λ

    // �ж��Ƿ�Ϊ������
    if (digit1 == digit5 && digit2 == digit4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}