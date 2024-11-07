#include <iostream>
using namespace std;

int myfun(int arr[7]) {
    int nonZeroCount = 0;
    int sum = 0;
    int product = 1;

    for (int i = 0; i < 7; ++i) {
        int isNonZero = !!arr[i];   // 将非零元素转换为1
        nonZeroCount += isNonZero;  // 增加非零计数
        sum += arr[i] * isNonZero;  // 累加非零元素
        product *= (1 + arr[i] - isNonZero); // 将非零元素乘到product中
    }

    int results[2] = { product, sum };   // 结果数组
    return results[nonZeroCount & 1];    // 根据非零个数的奇偶性选择返回值
}


int main() {
    int arr[7];
    cout << "Input: ";
    for (int i = 0; i < 7; ++i) {
        cin >> arr[i];
    }
    cout << "Output: " << myfun(arr) << endl;
    return 0;
}