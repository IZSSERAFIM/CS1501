#include <iostream>
#include <string>
using namespace std;

// 函数：计算西西弗斯数的转换
int transform(int n) {
    int even_count = 0;  // 偶数个数
    int odd_count = 0;   // 奇数个数
    int last_digit = std::to_string(n).length();  // 个位数

    // 遍历每一位数字，统计偶数和奇数的个数
    while (n > 0) {
        int digit = n % 10;
        if (digit % 2 == 0) {
            even_count++;  // 偶数
        } else {
            odd_count++;   // 奇数
        }
        n /= 10;  // 去掉最低位
    }

    // 生成新的三位数：百位为偶数个数，十位为奇数个数，个位为原数的个位
    return even_count * 100 + odd_count * 10 + last_digit;
}

int main() {
    int number;
    cout << "Input a natural number: ";
    cin >> number;

    // 输出初始的数字
    cout << number;

    // 不断转换，直到结果为123
    while (number != 123) {
        number = transform(number);  // 转换数字
        cout << " -> " << number;    // 输出转换后的结果
    }

    cout << endl;  // 换行
    return 0;
}