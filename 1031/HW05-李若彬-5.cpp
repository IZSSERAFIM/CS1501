#include <iostream>
using namespace std;

// 单词结构体
struct Word {
    char chars[11];  // 最大10个字符 + '\0'
    int len;        // 单词长度
};

// 合并后的单词组结构体
struct MergedWord {
    char chars[101];  // 最大10个单词每个10字符 + '\0'
    int len;         // 合并后长度
    int count;       // 包含原始单词数量
};

// 分割字符串为单词
int splitWords(const char* input, Word words[10]) {
    int wordCount = 0;
    int charIndex = 0;
    int inputLen = 0;
    
    // 获取输入字符串长度
    while (input[inputLen] != '\0') inputLen++;
    
    for (int i = 0; i <= inputLen; i++) {
        if (input[i] == ' ' || input[i] == '\0') {
            if (charIndex > 0) {
                words[wordCount].chars[charIndex] = '\0';
                words[wordCount].len = charIndex;
                wordCount++;
                charIndex = 0;
            }
        } else {
            words[wordCount].chars[charIndex++] = input[i];
        }
    }
    return wordCount;
}

// 复制字符串
void strCopy(char* dest, const char* src) {
    int i = 0;
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

// 连接字符串
void strCat(char* dest, const char* src) {
    int i = 0;
    while (dest[i] != '\0') i++;
    int j = 0;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
}

// 按长度分组并合并单词
int mergeWords(Word words[], int wordCount, MergedWord mergedWords[10]) {
    int mergedCount = 0;
    bool used[10] = {false};
    
    for (int i = 0; i < wordCount; i++) {
        if (used[i]) continue;
        
        mergedWords[mergedCount].chars[0] = '\0';
        mergedWords[mergedCount].len = 0;
        mergedWords[mergedCount].count = 0;
        
        // 找到所有相同长度的单词
        for (int j = i; j < wordCount; j++) {
            if (!used[j] && words[j].len == words[i].len) {
                strCat(mergedWords[mergedCount].chars, words[j].chars);
                mergedWords[mergedCount].len += words[j].len;
                mergedWords[mergedCount].count++;
                used[j] = true;
            }
        }
        mergedCount++;
    }
    return mergedCount;
}

// 冒泡排序合并后的单词组
void sortMergedWords(MergedWord mergedWords[], int mergedCount) {
    for (int i = 0; i < mergedCount - 1; i++) {
        for (int j = 0; j < mergedCount - 1 - i; j++) {
            bool shouldSwap = false;
            // 按长度升序
            if (mergedWords[j].len > mergedWords[j + 1].len) {
                shouldSwap = true;
            }
            // 长度相同时按单词数量降序
            else if (mergedWords[j].len == mergedWords[j + 1].len && 
                     mergedWords[j].count < mergedWords[j + 1].count) {
                shouldSwap = true;
            }
            
            if (shouldSwap) {
                MergedWord temp = mergedWords[j];
                mergedWords[j] = mergedWords[j + 1];
                mergedWords[j + 1] = temp;
            }
        }
    }
}

int main() {
    char input[1001];
    std::cout << "Input: ";
    cin.getline(input, 1001);
    
    // 分割单词
    Word words[10];
    int wordCount = splitWords(input, words);
    
    // 合并相同长度的单词
    MergedWord mergedWords[10];
    int mergedCount = mergeWords(words, wordCount, mergedWords);
    
    // 排序
    sortMergedWords(mergedWords, mergedCount);
    
    // 输出结果
    std::cout << "Output: ";
    for (int i = 0; i < mergedCount; i++) {
        if (i > 0) cout << " ";
        cout << mergedWords[i].chars;
    }
    cout << endl;
    
    return 0;
}