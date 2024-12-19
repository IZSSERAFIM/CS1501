#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1416;

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double radius) : radius(radius) {}
    double circum() const {
        return 2 * PI * radius;
    }
    double getArea() const override {
        return PI * radius * radius;
    }
};

class Cylinder {
private:
    Circle base;
    double height;
public:
    Cylinder(double radius, double height) : base(Circle(radius)), height(height) {}
    double bottomArea() const {
        return base.getArea();
    }
    double sideArea() const {
        return base.circum() * height;
    }
    double volume() const {
        return base.getArea() * height;
    }
    double getHeight() const {
        return height;
    }
};

int main() {
    double r, h;
    Cylinder* p;
    cout << "Input the parameters: ";
    cin >> r >> h;
    p = new Cylinder(r, h);
    cout << "Bottom Area: " << p->bottomArea() << endl;
    cout << "Side Area: " << p->sideArea() << endl;
    cout << "Volume: " << p->volume() << endl;
    cout << "Height: " << p->getHeight() << endl;

    return 0;
}