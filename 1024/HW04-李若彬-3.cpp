#include <iostream>
#include <vector>
#include <algorithm> // 用于 std::max

int main() {
    int r;
    std::cin >> r;

    // 定义三角形矩阵
    std::vector<std::vector<int>> triangle(r);
    for (int i = 0; i < r; ++i) {
        triangle[i].resize(i + 1); // 每一行的元素数量等于行号 + 1
        for (int j = 0; j <= i; ++j) {
            std::cin >> triangle[i][j];
        }
    }

    // 定义二维数组 f 用于存储从顶点到达每个位置的最大路径和
    std::vector<std::vector<int>> f(r, std::vector<int>(r, 0));

    // 初始化顶点
    f[0][0] = triangle[0][0];

    // 动态规划填充 f 数组
    for (int i = 1; i < r; ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0) {
                // 最左边的元素，只能从上一行的第一个元素过来
                f[i][j] = f[i-1][j] + triangle[i][j];
            } else if (j == i) {
                // 最右边的元素，只能从上一行的最后一个元素过来
                f[i][j] = f[i-1][j-1] + triangle[i][j];
            } else {
                // 其他元素，可以从左上方或者正（右）上方过来，取较大值
                f[i][j] = std::max(f[i-1][j-1], f[i-1][j]) + triangle[i][j];
            }
        }
    }

    // 找出最后一行的最大值
    int maxSum = 0;
    for (int j = 0; j < r; ++j) {
        maxSum = std::max(maxSum, f[r-1][j]);
    }

    std::cout << maxSum << std::endl;

    return 0;
}