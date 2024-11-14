#include <iostream>
using namespace std;

// 用于交换两个元素的函数
void swap(int* a, int* b, int* indexA, int* indexB) {
    int temp = *a;
    *a = *b;
    *b = temp;

    int tempIndex = *indexA;
    *indexA = *indexB;
    *indexB = tempIndex;
}

// 快速排序函数
void quickSort(int arr[], int index[], int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = (low - 1);

        for (int j = low; j <= high - 1; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j], &index[i], &index[j]);
            }
        }
        swap(&arr[i + 1], &arr[high], &index[i + 1], &index[high]);
        int pi = i + 1;

        quickSort(arr, index, low, pi - 1);
        quickSort(arr, index, pi + 1, high);
    }
}

// 二分查找函数
int search(int arr[], int index[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            return index[mid]; // 返回原始索引
        } else if (arr[mid] > key) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    return -1; // 未找到 key，返回 -1
}

int main() {
    int n;

    // 输入数组大小
    cout << "Please input n:";
    cin >> n;

    // 定义数组 arr 和 index，大小最多为 20
    int arr[20], index[20];

    // 输入 n 个整数
    cout << "Please input " << n << " integers:";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
        index[i] = i; // 记录原始索引
    }

    // 对数组进行快速排序，同时保持索引的顺序
    quickSort(arr, index, 0, n - 1);

    int key;

    // 输入要查找的 key
    cout << "Please input key:";
    cin >> key;

    // 调用二分查找函数
    int result = search(arr, index, n, key);

    // 输出结果
    if (result != -1) {
        cout << "Index=" << result << endl;
    } else {
        cout << "Not Found" << endl;
    }

    return 0;
}