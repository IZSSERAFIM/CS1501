#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Please input n:";
    cin >> n;

    // 动态分配数组 arr 用于存储每个人的状态，1表示在圈内，0表示已被淘汰
    int* arr = new int[n];  // 动态分配大小为 n 的数组
    for (int i = 0; i < n; ++i) {
        arr[i] = 1;  // 初始每个人都在圈内
    }

    int current = 0;  // 当前报数的位置
    int count = 0;    // 记录已经退出的人数
    int step = 0;     // 报数计数

    while (count < n - 1) {  // 当退出的人数少于总人数-1时继续
        if (arr[current] == 1) {  // 如果当前编号的人还在圈内
            step += 1;  // 进行报数
            if (step == 3) {  // 如果报数到3
                arr[current] = 0;  // 该人退出
                count += 1;  // 退出人数加1
                step = 0;  // 重置报数
            }
        }

        // 移动到下一个位置，形成环
        current = (current + 1) % n;
    }

    // 找到最后一个剩下的人
    for (int i = 0; i < n; ++i) {
        if (arr[i] == 1) {
            cout << "Last code:" << i + 1 << endl;  // 输出最后一个人的编号
            break;
        }
    }

    // 释放动态分配的内存
    delete[] arr;

    return 0;
}