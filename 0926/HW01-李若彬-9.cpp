#include <iostream>

using namespace std;

int main()
{
    char a[3];
    cin >> a[0] >> a[1] >> a[2];
    int n;
    cin >> n;
    a[0] -= 'A';
    a[1] -= 'A';
    a[2] -= 'A';
    a[0] = (a[0] - n + 26) % 26;
    a[1] = (a[1] - n + 26) % 26;
    a[2] = (a[2] - n + 26) % 26;
    a[0] += 'A';
    a[1] += 'A';
    a[2] += 'A';
    cout << a[0] << a[1] << a[2] << endl;
    return 0;
}