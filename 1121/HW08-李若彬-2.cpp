#include <iostream>
using namespace std;

int main() {
    // 动态分配内存存储句子
    char* sentence = new char[101];  // 最多 100 个字符 + 1 个结束符
    cout << "Input: ";
    cin.getline(sentence, 101);  // 读取句子，包含空格

    // 动态分配内存存储单词
    char** words = new char*[10];  // 最多 10 个单词
    for (int i = 0; i < 10; ++i) {
        words[i] = new char[101];  // 每个单词最多 100 个字符
    }

    // 分割单词
    int wordCount = 0;  // 记录单词个数
    int charIndex = 0;  // 字符索引
    for (int i = 0; sentence[i] != '\0'; ++i) {
        if (sentence[i] != ' ') {  // 非空格字符
            words[wordCount][charIndex++] = sentence[i];
        } else if (charIndex > 0) {  // 遇到空格且当前单词有字符
            words[wordCount][charIndex] = '\0';  // 结束当前单词
            wordCount++;
            charIndex = 0;  // 准备记录下一个单词
        }
    }
    if (charIndex > 0) {  // 最后一个单词
        words[wordCount][charIndex] = '\0';
        wordCount++;
    }

    // 输出单词个数
    cout << "Output: " << wordCount << endl;

    // 输入重新排序的数字串
    char* order = new char[11];  // 最多 10 位数字 + 1 个结束符
    cout << "Input: ";
    cin >> order;

    // 按顺序输出重新排列的句子
    cout << "Output: ";
    for (int i = 0; order[i] != '\0'; ++i) {
        int index = order[i] - '0';  // 将字符转换为整数
        if (index >= 0 && index < wordCount) {
            cout << words[index];
            if (order[i + 1] != '\0') {
                cout << " ";  // 单词之间加空格
            }
        }
    }
    cout << endl;

    // 释放动态分配的内存
    delete[] sentence;
    delete[] order;
    for (int i = 0; i < 10; ++i) {
        delete[] words[i];
    }
    delete[] words;

    return 0;
}