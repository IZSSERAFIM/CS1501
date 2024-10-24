#include <iostream>
#include <vector>
#include <climits> // 用于 INT_MIN 和 INT_MAX

int main() {
    int m, n;
    std::cout << "Please input m, n: ";
    std::cin >> m >> n;

    // 读取矩阵
    std::vector<std::vector<int>> mat(m, std::vector<int>(n));
    std::cout << "Please input array:\n";
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> mat[i][j];
        }
    }

    // 记录每行的最大值和每列的最小值
    std::vector<int> rowMax(m, INT_MIN); // 初始化为最小整数
    std::vector<int> colMin(n, INT_MAX); // 初始化为最大整数

    // 第一次遍历：找出每行的最大值和每列的最小值
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            // 更新当前行的最大值
            if (mat[i][j] > rowMax[i]) {
                rowMax[i] = mat[i][j];
            }
            // 更新当前列的最小值
            if (mat[i][j] < colMin[j]) {
                colMin[j] = mat[i][j];
            }
        }
    }

    bool found = false; // 用于标记是否找到鞍点

    // 第二次遍历：检查是否有元素是所在行的最大值且是所在列的最小值
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == rowMax[i] && mat[i][j] == colMin[j]) {
                std::cout << "mat[" << i << "][" << j << "]=" << mat[i][j] << std::endl;
                found = true;
            }
        }
    }

    // 如果没有找到任何鞍点，输出 "Not Found"
    if (!found) {
        std::cout << "Not Found" << std::endl;
    }

    return 0;
}