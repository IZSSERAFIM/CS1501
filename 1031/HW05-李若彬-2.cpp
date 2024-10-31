#include <iostream>
#include <cstring>

using namespace std;

// 每个字母和数字的摩尔斯电码定义
const char *morseCode[] = {
    ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
    "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
    "..-", "...-", ".--", "-..-", "-.--", "--..",
    ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.", "-----"
};

// 对应的字母和数字
const char letters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

// 找到字符对应的摩尔斯电码位置
int findIndexInLetters(char c) {
    for (int i = 0; i < 36; ++i) {
        if (letters[i] == c) {
            return i;
        }
    }
}

// 找到摩尔斯电码对应的字符
char findMorseToLetter(const char *morse) {
    for (int i = 0; i < 36; ++i) {
        if (strcmp(morseCode[i], morse) == 0) {
            return letters[i];
        }
    }
}

// 将输入的英文短语转换为摩尔斯电码输出
void englishToMorseCode(const char *input) {
    for (int i = 0; input[i] != '\0'; ++i) {
        char c = input[i];

        // 忽略空格，处理大写字母
        if (c == ' ') {
            cout << "   "; // 每个单词之间用三个空格分隔
            continue;
        }

        // 转换为大写
        if (c >= 'a' && c <= 'z') {
            c = c - 'a' + 'A';
        }

        int index = findIndexInLetters(c);
        if (index != -1) {
            cout << morseCode[index] << " "; // 每个字母之间用一个空格分隔
        }
    }
    cout << endl;
}

// 将输入的摩尔斯电码转换为英文短语输出
void morseToEnglishCode(const char *input) {
    char morse[10]; // 临时存储单个摩尔斯电码
    int morseIndex = 0;

    for (int i = 0; input[i] != '\0'; ++i) {
        if (input[i] != ' ') {
            morse[morseIndex++] = input[i]; // 收集摩尔斯电码符号
        } else {
            if (morseIndex > 0) { // 如果到达空格并且已经有了摩尔斯电码
                morse[morseIndex] = '\0'; // 结束当前摩尔斯电码
                cout << findMorseToLetter(morse); // 输出对应的字母
                morseIndex = 0; // 重置索引
            }

            // 处理单词之间的三个空格
            int spaceCount = 1;
            while (input[i] == ' ') {
                spaceCount++;
                i++;
            }
            i--;

            if (spaceCount >= 3) {
                cout << " "; // 如果是三个空格，则是单词间隔
            }
        }
    }

    // 处理最后一个摩尔斯电码
    if (morseIndex > 0) {
        morse[morseIndex] = '\0';
        cout << findMorseToLetter(morse);
    }

    cout << endl;
}

int main() {
    char input[100];

    // 输入英文短语并转换成摩尔斯电码
    cout << "Input English: ";
    cin.getline(input, 100);
    englishToMorseCode(input);

    // 输入摩尔斯电码并转换成英文短语
    cout << "Input Morse code: ";
    cin.getline(input, 100);
    morseToEnglishCode(input);

    return 0;
}