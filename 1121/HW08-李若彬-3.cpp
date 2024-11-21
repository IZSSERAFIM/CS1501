#include <iostream>
using namespace std;
// 此处填补 2 行代码
int myfun(int* a, int* b);
char* myfun(int &a, int &b);
char result[10];

int main()
{
    int x, y;
    cout << "Input: ";
    cin >> x >> y;
    cout << "Output: ";
    cout << myfun(x, y);
    cout << x << ' ' << y;
    return 0;
}

int myfun(int *a, int *b)
{
    int c = *a - *b;
    *a *= 2;
    *b *= 3;
    return c;
}

// 此处定义一个函数
char* myfun(int &a, int &b){
    result[0] = (a - b) % 10 + '0';
    result[1] = ' ';
    a *= 3;
    b *= 2;
    return result;
}