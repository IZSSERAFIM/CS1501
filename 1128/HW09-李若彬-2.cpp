#include <iostream>
#include <algorithm>
using namespace std;

struct date {
    int year, month, day;
};

struct Person {
    char name[21];
    date birth;
    char phone[12];
    char addr[51];
};

bool compareByAge(const Person &a, const Person &b) {
    if (a.birth.year != b.birth.year)
        return a.birth.year > b.birth.year;
    if (a.birth.month != b.birth.month)
        return a.birth.month > b.birth.month;
    return a.birth.day > b.birth.day;
}

int main() {
    int n;
    cout << "Please input n(n<10): ";
    cin >> n;

    Person people[10];
    for (int i = 0; i < n; i++) {
        cin >> people[i].name >> people[i].birth.year >> people[i].birth.month >> people[i].birth.day >> people[i].phone;
        cin.getline(people[i].addr, 51);
    }

    sort(people, people + n, compareByAge);

    for (int i = 0; i < n; i++) {
        cout << people[i].name << " " << people[i].birth.year << "/" << people[i].birth.month << "/" << people[i].birth.day << " " << people[i].phone << " " << people[i].addr << endl;
    }
    return 0;
}