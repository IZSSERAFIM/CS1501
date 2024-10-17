#include <iostream>
using namespace std;

int main() {
    int K;  // 输入的金额
    cout << "Input the change: ";
    cin >> K;

    int methods = 0;  // 记录满足条件的组合数量

    // 使用三重循环遍历1分、2分、5分硬币的数量
    for (int x = 1; x <= K; x++) {  // 至少有1枚1分硬币
        for (int y = 1; y <= K / 2; y++) {  // 至少有1枚2分硬币
            for (int z = 1; z <= K / 5; z++) {  // 至少有1枚5分硬币
                if (x + 2 * y + 5 * z == K) {
                    methods++;  // 如果总金额等于K，计数加一
                }
            }
        }
    }

    // 输出结果
    cout << "Methods=" << methods << endl;

    return 0;
}