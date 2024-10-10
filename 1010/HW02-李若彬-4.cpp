#include <iostream>

using namespace std;

// 计算两点之间距离的平方
int distanceSquared(int x1, int y1, int x2, int y2) {
    return (x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1);
}

bool areFourPointsCyclic(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
    // 计算所有边的长度平方
    int AB = distanceSquared(x1, y1, x2, y2); // AB
    int BC = distanceSquared(x2, y2, x3, y3); // BC
    int CD = distanceSquared(x3, y3, x4, y4); // CD
    int DA = distanceSquared(x4, y4, x1, y1); // DA
    int AC = distanceSquared(x1, y1, x3, y3); // AC
    int BD = distanceSquared(x2, y2, x4, y4); // BD

    int cosCAD_2 = (AC * AC + DA * DA - CD * CD) * (AC * AC + DA * DA - CD * CD) * (2 * BC * BD) * (2 * BC * BD);
    int cosCBD_2 = (BC * BC - BD * BD - CD * CD) * (BC * BC - BD * BD - CD * CD) * (2 * AC * DA) * (2 * AC * DA);

    if (cosCAD_2 == cosCBD_2) {
        if (((y4 - y3) * x1 + (x3 - x4) * y1 + y3 * x4 - y4 * x3) * (
                (y4 - y3) * x2 + (x3 - x4) * y2 + y3 * x4 - y4 * x3) > 0) {
            if (((AC * AC + DA * DA > CD * CD) && (BC * BC + BD * BD > CD * CD)) || (
                    (AC * AC + DA * DA < CD * CD) && (BC * BC + BD * BD < CD * CD))) {
                return true;
            } else if (((AC * AC + DA * DA == CD * CD) && (BC * BC + BD * BD == CD * CD))) {
                return true;
            } else {
                return false;
            }
        } else if (((y4 - y3) * x1 + (x3 - x4) * y1 + y3 * x4 - y4 * x3) * (
                       (y4 - y3) * x2 + (x3 - x4) * y2 + y3 * x4 - y4 * x3) < 0) {
            if (((AC * AC + DA * DA > CD * CD) && (BC * BC + BD * BD < CD * CD)) || (
                    (AC * AC + DA * DA < CD * CD) && (BC * BC + BD * BD > CD * CD))) {
                return true;
            } else if (((AC * AC + DA * DA == CD * CD) && (BC * BC + BD * BD == CD * CD))) {
                return true;
            }
        } else {
            return false;
        }
    }
    return false;
}

int main() {
    int x1, y1, x2, y2, x3, y3, x4, y4;

    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

    if (areFourPointsCyclic(x1, y1, x2, y2, x3, y3, x4, y4)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
