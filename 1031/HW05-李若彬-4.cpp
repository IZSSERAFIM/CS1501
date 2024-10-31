#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    string input;
    cout << "Input: ";
    cin >> input;

    int number = 0;

    // 判断输入格式，分别处理十进制、八进制和十六进制
    if (input[0] == '0') {
        if (input[1] == 'x' || input[1] == 'X') {
            // 十六进制输入 (0x 或 0X 开头)
            number = stoi(input, nullptr, 16);  // 使用基数为16进行转换
            cout << "Output: hexadecimal, " << number << ", " 
                 << showbase << oct << number << ", " 
                 << hex << number << endl;
        } else {
            // 八进制输入 (0开头且不是0x)
            number = stoi(input, nullptr, 8);  // 使用基数为8进行转换
            cout << "Output: octonary, " << number << ", "
                 << showbase << oct << number << ", " 
                 << hex << number << endl;
        }
    } else {
        // 十进制输入
        number = stoi(input, nullptr, 10);  // 使用基数为10进行转换
        cout << "Output: decimal, " << number << ", " 
             << showbase << oct << number << ", " 
             << hex << number << endl;
    }

    return 0;
}