#include <iostream>
using namespace std;

int main() {
    int a, n;
    cout << "Input a, n: ";
    cin >> a >> n;

    int sum = 0;
    int term = 0;

    for (int i = 1; i <= n; i++) {
        term = term * 10 + a;
        sum += term;
    }

    cout << "Sum=" << sum << endl;
    return 0;
}
