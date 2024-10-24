#include <iostream>
#include <vector>

int main() {
    int n, k;
    std::cin >> n >> k;

    // 初始化所有灯为关闭状态，false 表示关，true 表示开
    std::vector<bool> lights(n + 1, false); // 使用 n+1 的大小，忽略 index 0

    // 逐个处理每个人的操作
    for (int person = 1; person <= k; ++person) {
        for (int i = person; i <= n; i += person) {
            lights[i] = !lights[i]; // 翻转灯的状态
        }
    }

    // 输出所有处于开启状态的灯
    bool anyOpen = false;
    for (int i = 1; i <= n; ++i) {
        if (lights[i]) {
            std::cout << i << " "; // 输出灯的编号
            anyOpen = true;
        }
    }
    
    if (!anyOpen) {
        std::cout << "No lights are on."; // 如果没有灯处于开启状态
    }

    std::cout << std::endl;

    return 0;
}