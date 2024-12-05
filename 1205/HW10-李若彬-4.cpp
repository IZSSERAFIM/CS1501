#include <iostream>
#include <cstring>
using namespace std;

class SkillList {
private:
    char** skills;
    int maxSkills;
    int currentSkills;
    bool isascending = true;
    void sortSkills() const {
        bool ascending = isascending;
        for (int i = 0; i < currentSkills - 1; ++i) {
            for (int j = 0; j < currentSkills - i - 1; ++j) {
                if ((ascending && strcmp(skills[j], skills[j + 1]) > 0) ||
                    (!ascending && strcmp(skills[j], skills[j + 1]) < 0)) {
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
        cout << "Destruct SkillList: ";
        for (int i = currentSkills - 1; i >= 0; --i) {
            cout << skills[i] << (i > 0 ? ", " : "");
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
    cout << "Learned skills: ";
    pMember->display();
    delete pMember;
    return 0;
}
