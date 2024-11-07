#include <iostream>
using namespace std;

bool func(char array[], int len);

int main() {
    char ch[20];
    bool result;

    cout << "Input: ";
    cin >> ch;

    int len = 0;
    while (ch[len] != '\0') len++;
    result = func(ch, len);
    cout << "Output: " << (result ? "Yes" : "No") << endl;

    return 0;
}

bool func(char array[], int len) {
    return (len <= 1) || (array[0] == array[len - 1] && func(array + 1, len - 2));
}