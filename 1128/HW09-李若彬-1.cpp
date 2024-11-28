#include <iostream>
using namespace std;

struct Complex {
    int a, b;
};

Complex Input() {
    int x, y;
    cin >> x >> y;
    return {x, y};
}

Complex Add(Complex num1, Complex num2) {
    return {num1.a + num2.a, num1.b + num2.b};
}

Complex Multiply(Complex num1, Complex num2) {
    return {num1.a * num2.a - num1.b * num2.b, num1.a * num2.b + num1.b * num2.a};
}

void Output(Complex num) {
    if(num.a == 0 && num.b == 0) cout << 0 << endl;
    else if(num.a == 0) cout << num.b << "i" << endl;
    else if(num.b == 0) cout << num.a << endl;
    else if(num.b < 0) cout << num.a << "-" << -num.b << "i" << endl;
    else cout << num.a << "+" << num.b << "i" << endl;
}

int main() {
    Complex num1, num2, sum, product;
    cout << "Please input integers a,b,c,d: ";
    num1 = Input(); num2 = Input(); // Input 是輸入函數
    sum = Add(num1, num2); // Add 是加法函數
    product = Multiply(num1, num2); // Multiply 是乘法函數
    cout << "Sum: "; Output(sum); // Output 是輸出函數
    cout << "Product: "; Output(product);
    return 0;
}