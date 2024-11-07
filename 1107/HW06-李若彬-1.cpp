#include <iostream>
using namespace std;

// 判断一个数字是否为完全数
bool isPerfectNumber(int num) {
    int sum = 0;
    
    // 遍历所有小于num的因子
    for (int i = 1; i <= num / 2; ++i) {
        if (num % i == 0) {
            sum += i;  // 将因子相加
        }
    }
    
    return sum == num;  // 如果因子和等于num，则是完全数
}

int main() {
    int m, n;
    
    // 输入m和n的值
    cout << "Please input m, n:";
    cin >> m >> n;

    // 输出范围内的完全数
    cout << "Perfect number in [" << m << "," << n << "]:";
    bool found = false;

    // 遍历m到n之间的每个数
    for (int i = m; i <= n; ++i) {
        if (isPerfectNumber(i)) {
            cout << i << " ";  // 输出完全数
            found = true;
        }
    }

    // 如果没有找到完全数
    if (!found) {
        return 0;
    }

    cout << endl;

    return 0;
}