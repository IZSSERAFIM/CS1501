#include <iostream>
using namespace std;

int main() {
    char input;
    cout << "������һ����ĸ: ";
    cin >> input;

    // �ж��Ƿ�Ϊ��ĸ (a-z �� A-Z)
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        // ��������ĸת��Сд��ĸ
        char lowerInput = input | 0x20;  // λ���㣺����д��ĸ���Сд��ĸ

        // ʹ�� switch �ж��Ƿ�ΪԪ����ĸ
        switch (lowerInput) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cout << "Ԫ��" << endl;
            break;
            default:
                cout << "����" << endl;
        }
    } else {
        cout << "����Ӣ����ĸ" << endl;
    }

    return 0;
}