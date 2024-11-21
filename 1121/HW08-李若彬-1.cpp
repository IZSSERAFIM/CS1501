#include <iostream>
using namespace std;

// 计算字符串数组中最短字符串的有效长度
int minlen(char* str[], int n) {
    int minLength = 20;  // 初始化为最大长度（20）
    for (int i = 0; i < n; ++i) {
        int length = 0;
        while (str[i][length] != '\0') {  // 手动计算字符串长度
            length++;
        }
        if (length < minLength) {  // 更新最短长度
            minLength = length;
        }
    }
    return minLength;
}

int main() {
    int n;
    cout << "Input: ";
    cin >> n;

    if (n < 1 || n > 5) {
        return 1;
    }

    char* str[5];  // 定义字符串指针数组，最多存储 5 个字符串
    for (int i = 0; i < n; ++i) {
        str[i] = new char[21];  // 动态分配内存，每个字符串最大长度为 20
        cin >> str[i];  // 读取字符串
    }

    // 调用 minlen 函数计算最短字符串的长度
    int result = minlen(str, n);
    cout << "Output: " << result << endl;

    // 释放动态分配的内存
    for (int i = 0; i < n; ++i) {
        delete[] str[i];
    }

    return 0;
}