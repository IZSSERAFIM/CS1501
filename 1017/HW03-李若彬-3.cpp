#include <iostream>
using namespace std;

int main() {
    char ch;
    
    cout << "Input: ";
    
    // 循环读取每个字符，直到遇到句号 '.'
    while (cin.get(ch)) {
        if (ch == '.') {  // 如果到句号，结束读取
            cout << ch;   // 输出句号
            break;
        }
        if (ch != ' ') {  // 如果不是空格，直接输出
            cout << ch;
        }
    }

    cout << endl;  // 换行
    return 0;
}