#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1416

class Shape {
public:
    virtual double getArea() const = 0;
    virtual ~Shape() {}
};

class Triangle : public Shape {
private:
    double a, b, c;
public:
    Triangle(double a, double b, double c) : a(a), b(b), c(c) {}
    double getArea() const override {
        double s = (a + b + c) / 2;
        return sqrt(s * (s - a) * (s - b) * (s - c));
    }
};

class Rectangle : public Shape {
private:
    double length, width;
public:
    Rectangle(double length, double width) : length(length), width(width) {}
    double getArea() const override {
        return length * width;
    }
};

class Square : public Rectangle {
public:
    Square(double side) : Rectangle(side, side) {}
};

class Ellipse : public Shape {
private:
    double majorAxis, minorAxis;
public:
    Ellipse(double majorAxis, double minorAxis) : majorAxis(majorAxis), minorAxis(minorAxis) {}
    double getArea() const override {
        return PI * majorAxis * minorAxis;
    }
};

class Circle : public Ellipse {
public:
    Circle(double radius) : Ellipse(radius, radius) {}
};

int main() {
    char flag;
    double a, b, c;
    Shape *p;
    cout << "Select the shape: ";
    cin >> flag;
    cout << "Input the parameters: ";
    switch (flag) {
    case 'T': cin >> a >> b >> c; p = new Triangle(a, b, c); break;
    case 'R': cin >> a >> b; p = new Rectangle(a, b); break;
    case 'S': cin >> a; p = new Square(a); break;
    case 'E': cin >> a >> b; p = new Ellipse(a, b); break;
    case 'C': cin >> a; p = new Circle(a); break;
    default: p = NULL;
    }
    cout << "Output: " << (p? p->getArea() : 0);
    return 0;
}