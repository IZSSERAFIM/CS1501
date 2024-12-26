#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

struct Member {
    char name[10];
    char type[10];
    int hp;
    int atk;
    int def;
    char skill[4][20];
};

bool findMember(fstream &file, const string &name) {
    while (!file.eof()) {
        Member member;
        file.read((char *)&member, sizeof(Member));
        if (strcmp(member.name, name.c_str()) == 0) {
            return true;
        }
    }
    return false;
}

void modifyRecord(fstream &file, const string &name, int field, const string &value) {
    file.seekg(0, ios::beg);
    while (!file.eof()) {
        Member member;
        file.read((char *)&member, sizeof(Member));
        if (strcmp(member.name, name.c_str()) == 0) {
            switch (field) {
                case 1:
                    strcpy(member.type, value.c_str());
                    break;
                case 2:
                    member.hp = stoi(value);
                    break;
                case 3:
                    member.atk = stoi(value);
                    break;
                case 4:
                    member.def = stoi(value);
                    break;
                case 5:
                case 6:
                case 7:
                case 8:
                    strcpy(member.skill[field - 5], value.c_str());
                    break;
                default:
                    cout << "Invalid field" << endl;
                    return;
            }
            file.seekp(-sizeof(Member), ios::cur);
            file.write((char *)&member, sizeof(Member));
            file.seekg(0, ios::end);
            cout << "Revision complete" << endl;
            return;
        }
    }
}

int main() {
    string filename = "save"; // 假设存档文件名为save
    fstream file(filename, ios::binary | ios::in | ios::out);

    if (!file) {
        cerr << "Unable to open file" << endl;
        return 1;
    }

    string name;
    cout << "Name: ";
    cin >> name;

    if (!findMember(file, name)) {
        cout << "Not found" << endl;
    } else {
        cout << "Field and Value: ";
        int field;
        string value;
        cin >> field >> value;
        modifyRecord(file, name, field, value);
    }

    file.close();
    return 0;
}