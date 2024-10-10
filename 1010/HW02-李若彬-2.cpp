#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "请输入一个5位整数: ";
    cin >> num;

    // 提取各个位上的数字
    int digit1 = num / 10000;         // 第一位
    int digit2 = (num / 1000) % 10;   // 第二位
    int digit4 = (num / 10) % 10;     // 第四位
    int digit5 = num % 10;            // 第五位

    // 判断是否为回文数
    if (digit1 == digit5 && digit2 == digit4) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}