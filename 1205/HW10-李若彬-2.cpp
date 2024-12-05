#include <iostream>
#include <cstring>
using namespace std;

class LongLongInt {
private:
    char* number;
public:
    LongLongInt(const char* num) {
        int len = strlen(num);
        number = new char[len + 1];
        strcpy(number, num);
    }
    LongLongInt(const LongLongInt& other) {
        int len = strlen(other.number);
        number = new char[len + 1];
        strcpy(number, other.number);
    }
    ~LongLongInt() {
        delete[] number;
    }
    void add(const LongLongInt& b, int x) {
        int len = strlen(b.number);
        int carry = x;
        for (int i = len - 1; i >= 0; --i) {
            int sum = (b.number[i] - '0') + carry;
            number[i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry > 0) {
            char* newNumber = new char[len + 2];
            newNumber[0] = carry + '0';
            strcpy(newNumber + 1, number);
            delete[] number;
            number = newNumber;
        }
    }
    void add(const LongLongInt& b, const LongLongInt& c) {
        int len1 = strlen(b.number);
        int len2 = strlen(c.number);
        int maxLen = max(len1, len2);
        char* result = new char[maxLen + 2];
        result[maxLen + 1] = '\0';

        int carry = 0;
        for (int i = 0; i < maxLen; ++i) {
            int digit1 = (i < len1) ? b.number[len1 - 1 - i] - '0' : 0;
            int digit2 = (i < len2) ? c.number[len2 - 1 - i] - '0' : 0;
            int sum = digit1 + digit2 + carry;
            result[maxLen - i] = (sum % 10) + '0';
            carry = sum / 10;
        }
        if (carry > 0) {
            result[0] = carry + '0';
            delete[] number;
            number = result;
        } else {
            delete[] number;
            number = new char[maxLen + 1];
            strcpy(number, result + 1);
            delete[] result;
        }
    }
    char* display() const {
        return number;
    }
};

int main() {
    int n, x;
    cout << "Number of digits: ";
    cin >> n; cin.get();
    char* p = new char[n + 1];
    cout << "Input: ";
    for (int i = 0; i < n; i++) cin.get(p[i]);
    p[n] = '\0';
    LongLongInt a(p); delete[] p;
    LongLongInt b = a;
    cout << "Add: ";
    cin >> x;
    b.add(a, x);
    cout << "Output b: " << b.display() << endl;
    a.add(b, a);
    cout << "Output a: " << a.display() << endl;
    return 0;
}