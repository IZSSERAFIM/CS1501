#include <iostream>

using namespace std;

int main()
{
    cout << "请输入一个三位整数：";
    int a;
    cin >> a;
    cout <<a<<"的百位数字是"<<a/100<<"，十位数字是"<<(a/10)%10<<"，个位数字是"<<a%10<<endl;
    return 0;
}
