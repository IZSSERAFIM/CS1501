#include <iostream>
using namespace std;
class Point {
public:
    int x, y, z;

    Point(int x = 0, int y = 0, int z = 0) : x(x), y(y), z(z) {}

    friend istream& operator>>(istream& in, Point& p) {
        in >> p.x >> p.y >> p.z;
        return in;
    }

    friend ostream& operator<<(ostream& out, const Point& p) {
        out << '(' << p.x << ',' << p.y << ',' << p.z << ')';
        return out;
    }

    Point operator-() const {
        return Point(-x, -y, -z);
    }
};

int main() {
    Point p1, p2;
    cin >> p1;
    p2 = -p1;
    cout << p2;
    return 0;
}