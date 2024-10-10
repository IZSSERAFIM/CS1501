#include <iostream>
using namespace std;

int main() {
    char input;
    cout << "请输入一个字母: ";
    cin >> input;

    // 判断是否为字母 (a-z 或 A-Z)
    if ((input >= 'a' && input <= 'z') || (input >= 'A' && input <= 'Z')) {
        // 将输入字母转成小写字母
        char lowerInput = input | 0x20;  // 位运算：将大写字母变成小写字母

        // 使用 switch 判断是否为元音字母
        switch (lowerInput) {
            case 'a':
            case 'e':
            case 'i':
            case 'o':
            case 'u':
                cout << "元音" << endl;
            break;
            default:
                cout << "辅音" << endl;
        }
    } else {
        cout << "不是英文字母" << endl;
    }

    return 0;
}