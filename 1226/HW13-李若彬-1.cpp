#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool compareFiles(const string& file1, const string& file2) {
    if(file1 == file2) {
        cout << "Same file. " << endl;
        return true;
    }

    ifstream f1(file1, ios::in);
    ifstream f2(file2, ios::in);

    if (!f1.is_open() || !f2.is_open()) {
        cerr << "Error opening files." << endl;
        return false;
    }

    f1.seekg(0, ios::end);
    f2.seekg(0, ios::end);
    if (f1.tellg() != f2.tellg()) {
        f1.seekg(0);
        f2.seekg(0);
        int line = 0;
        int col = 0;
        char c1, c2;
        while (f1.get(c1) && f2.get(c2)) {
            if (c1 != c2) {
                cout << line << ", " << col << endl;
                return false;
            }
            if (c1 == '\n') {
                line++;
                col = 0;
            } else {
                col++;
            }
        }
        if(f1.get(c1))
        {
            if(c1 == '\n')
            {
                cout << line + 1 << ", " << 0 << endl;
                return false;
            }
            else
            {
                cout << line << ", " << col + 1 << endl;
                return false;
            }
        } else if (f2.get(c2)) {
            if(c2 == '\n')
            {
                cout << line + 1 << ", " << 0 << endl;
                return false;
            }
            else
            {
                cout << line << ", " << col + 1 << endl;
                return false;
            }
        }
    }
    f1.seekg(0);
    f2.seekg(0);
    int line = 0;
    int col = 0;
    char c1, c2;
    while (f1.get(c1) && f2.get(c2)) {
        if (c1 != c2) {
            cout << line << ", " << col << endl;
            return false;
        }
        if (c1 == '\n') {
            line++;
            col = 0;
        } else {
            col++;
        }
    }
    cout << "Two files are equal." << endl;
    f1.close();
    f2.close();
    return true;
}

int main() {
    string file1, file2;
    cout << "Input: ";
    cin >> file1 >> file2;
    compareFiles(file1, file2);

    return 0;
}