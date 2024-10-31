#include <iostream>
#include <cctype>
using namespace std;

// 获取用户输入的第一个大写字母
char getUChar() {
    char ch;
    while (true) {
        cout << "Input: ";
        string input;
        getline(cin, input); // 使用getline获取整行输入
        for (char ch : input) { // 遍历输入的每个字符
            if (isupper(ch)) {
                return ch;
            }
        }
    }
}

int main() {
    char result = getUChar();
    cout << "Output: " << result << endl;
    return 0;
}
