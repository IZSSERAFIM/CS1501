#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    float f;
    cin >> f;
    float c = round(5 * (f - 32) / 9 * 100) / 100;
    cout << fixed << setprecision(2) << c << endl;
    return 0;
}