#include <iostream>
#include <cstring>
using namespace std;

class SkillList {
private:
    char** skills;
    int maxSkills;
    int currentSkills;
    void sortSkills() const {
        for (int i = 0; i < currentSkills - 1; ++i) {
            for (int j = 0; j < currentSkills - i - 1; ++j) {
                if (strcmp(skills[j], skills[j + 1]) > 0) {
                    char* temp = skills[j];
                    skills[j] = skills[j + 1];
                    skills[j + 1] = temp;
                }
            }
        }
    }
public:
    SkillList(int max) : maxSkills(max), currentSkills(0) {
        skills = new char*[max];
        cout << "Construct SkillList: None" << endl;
    }
    ~SkillList() {
        if(currentSkills == 0) {
            cout << "Destruct SkillList: None" << endl;
            return;
        }
        for (int i = 0; i < currentSkills - 1; ++i) {
            for (int j = 0; j < currentSkills - i - 1; ++j) {
                if (strcmp(skills[j], skills[j + 1]) < 0) {
                    char* temp = skills[j];
                    skills[j] = skills[j + 1];
                    skills[j + 1] = temp;
                }
            }
        }
        cout << "Destruct SkillList: ";
        for (int i = 0; i < currentSkills; ++i) {
            cout << skills[i] << (i < currentSkills-1 ? ", " : "");
        }
        cout << endl;
        for (int i = 0; i < currentSkills; ++i) {
            delete[] skills[i];
        }
        delete[] skills;
    }
    bool add(const char* skillName) {
        if (currentSkills >= maxSkills) {
            return false;
        }
        skills[currentSkills] = new char[strlen(skillName) + 1];
        strcpy(skills[currentSkills], skillName);
        currentSkills++;
        return true;
    }
    void display() const {
        if (currentSkills == 0) {
            cout << "None" << endl;
        } else {
            sortSkills();
            for (int i = 0; i < currentSkills; ++i) {
                cout << skills[i] << (i < currentSkills - 1 ? ", " : "");
            }
            cout << endl;
        }
    }
    bool operator[](const char* skillName) const {
        for (int i = 0; i < currentSkills; ++i) {
            if (strcmp(skills[i], skillName) == 0) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    int maxNum;
    cout << "Max number of skills: ";
    cin >> maxNum; cin.get();
    SkillList *pMember = new SkillList (maxNum);
    while (true) {
        char *skillName = new char[20];
        cout << "Learn a new skill: ";
        cin.getline(skillName, 20);
        if (!pMember->add(skillName)) {
            delete skillName;
            break;
        }
    }
    int select;
    cout << "Select 1-Show learned skills, 2-Search a target skill: ";
    cin >> select; cin.get();
    if (select == 1) {
        cout << "Learned skills: ";
        pMember->display();
    } else if (select == 2) {
        char skillTarget[20];
        cout << "Target skill: "; cin.getline(skillTarget, 20);
        cout << "Search result: ";
        cout << ((*pMember)[skillTarget] ? "Yes" : "No") << endl;
    }
    delete pMember;
    return 0;
}