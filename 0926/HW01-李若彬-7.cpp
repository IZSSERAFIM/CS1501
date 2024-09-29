#include <iostream>

using namespace std;

int main() {
    string a;
    getline(cin, a);
    cout << a.substr(0, 3) << endl;
    return 0;
}
