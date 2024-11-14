#include <iostream>
using namespace std;

int main() {
    // 定义两个长度为 20 的字符数组
    char str1[20], str2[20];

    // 定义一个字符变量和字符指针
    char temp;
    char* ptr;

    // 输入两个字符串
    cout << "Input: ";
    cin >> str1;
    cout << "Input: ";
    cin >> str2;

    // 对两个字符串的每个字符进行交换，直到遇到空字符
    int i = 0;
    while (str1[i] != '\0' && str2[i] != '\0') {
        // 交换不为空的字符
        ptr = &str1[i];    // 保存 str1[i] 的值
        temp = str1[i];    // 保存 str1[i] 的值
        str1[i] = str2[ptr - str1]; // 把 str2[i] 赋值给 str1[i]
        str2[ptr - str1] = temp;    // 把原来的 str1[i] 赋值给 str2[i]
        i++;               // 移动到下一个字符
    }

    // 输出结果
    cout << "Output: " << str1 << endl;
    cout << "Output: " << str2 << endl;

    return 0;
}