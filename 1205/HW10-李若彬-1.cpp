#include <iostream>
using namespace std;

class Circle
{
private:
    int x, y; // 圆心坐标
    int r; // 半径

public:
    // 构造函数
    Circle(int x = 0, int y = 0, int r = 0) : x(x), y(y), r(r)
    {
    }

    // 获取圆心坐标
    void getO(int& outX, int& outY)
    {
        outX = x;
        outY = y;
    }

    // 获取半径
    int getR()
    {
        return r;
    }

    // 设置半径
    void setR(int newR)
    {
        r = newR;
    }

    // 移动圆的位置
    void moveTo(int newX, int newY)
    {
        x = newX;
        y = newY;
    }

    // 打印圆的信息
    void display()
    {
        cout << "X = " << x << ", Y = " << y << ", Radius = " << r << endl;
    }
};

int main()
{
    Circle a, b;
    int x, y, r;

    a.getO(x, y);
    cout << "The center of Circle A is: " << x << ", " << y << endl;
    cout << "Set the radius of Circle A to: ";
    cin >> r;
    a.setR(r);
    cout << "The radius of Circle A is: " << a.getR() << endl;

    b = a;
    cout << "Move the center of Circle B to: ";
    cin >> x >> y;
    b.moveTo(x, y);
    b.getO(x, y);
    cout << "The center of Circle B is: " << x << ", " << y << endl;
    b.display();

    return 0;
}
