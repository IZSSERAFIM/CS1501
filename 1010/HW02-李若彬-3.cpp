#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double amount;   // 加油量
    int type;        // 油品种类
    char service;    // 服务类型

    // 输入加油量、油品种类和服务类型
    cout << "Input amount: ";
    cin >> amount;

    cout << "Input type: ";
    cin >> type;

    cout << "Input service: ";
    cin >> service;

    // 油品价格
    double price = 0.0;
    switch (type) {
        case 90:
            price = 5.82;
        break;
        case 93:
            price = 5.96;
        break;
        case 97:
            price = 6.36;
        break;
        case 0:
            price = 5.59;
        break;
        default:
            cout << "Invalid oil type!" << endl;
        return 1;  // 退出程序
    }

    // 折扣计算
    double discount = 1.0;
    if (service == 's') {
        discount = 0.95;  // 自助服务
    } else if (service == 'a') {
        discount = 0.97;  // 协助服务
    } else {
        cout << "Invalid service type!" << endl;
        return 1;  // 退出程序
    }

    // 计算总金额
    double total = amount * price * discount;

    // 输出结果，保留2位小数
    cout << "Output: " << fixed << setprecision(2) << total << endl;

    return 0;
}