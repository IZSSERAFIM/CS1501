#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    char x, y;
    cin >> x >> y;

    // 将字符转换为大写字母
    x &= ~32;
    y &= ~32;

    // 将字母转换为数字
    int a = x - 'A' + 1;
    int b = y - 'A' + 1;

    // 输出四位整数码
    cout << setw(2) << setfill('0') << a;
    cout << setw(2) << setfill('0') << b << endl;

    return 0;
}