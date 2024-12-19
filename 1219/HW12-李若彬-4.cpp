#include <iostream>
#include <cstdlib>
#include <cstdint>
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
    }
    ~SkillList() {
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

class Member {
private:
    string name;
    int type;
    int hp, atk, def;
    SkillList skills;

public:
    Member(const string& name, int type, int hp, int atk, int def)
        : name(name), type(type), hp(hp), atk(atk), def(def), skills(10) {}

    bool MemberTraining(int trainingType) {
        static const double rate[3][4] = {
            {0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}
        };
        double successRate = rate[type][trainingType];
        bool success = ((double)rand() / RAND_MAX) <= successRate;

        if (success) {
            switch (trainingType) {
            case 0: hp += 1; cout << name << " Success, HP+1\n"; break;
            case 1: atk += 1; cout << name << " Success, ATK+1\n"; break;
            case 2: def += 1; cout << name << " Success, DEF+1\n"; break;
            case 3:
                cout << name;
                if (type == 0 && !skills["Taunt"]) {
                    skills.add("Taunt");
                    cout << " Success, Skill \"Taunt\" is learned\n";
                } else if (type == 1 && !skills["Focus"]) {
                    skills.add("Focus");
                    cout << " Success, Skill \"Focus\" is learned\n";
                } else if (type == 2) {
                    if (!skills["Heal"]) {
                        skills.add("Heal");
                        cout << " Success, Skill \"Heal\" is learned\n";
                    } else if (!skills["Cure"]) {
                        skills.add("Cure");
                        cout << " Success, Skill \"Cure\" is learned\n";
                    } else {
                        cout << " Success, No more skills to learn\n";
                    }
                }
                break;
            }
        } else {
            cout << name << " Failure\n";
        }
        return success;
    }

    void OutputStatus() const {
        const char* classNames[] = {"Warrior", "Archer", "Priest"};
        cout << name << " " << classNames[type] << " Status: "
             << "HP " << hp << ", "
             << "ATK " << atk << ", "
             << "DEF " << def << ", "
             << "Skill: ";
        skills.display();
    }

    void Transfer() {
        int newClass;
        cout << "To Class (0-Warrior, 1-Archer, 2-Priest): ";
        cin >> newClass;
        type = newClass;
        cout << name << " becomes " << (newClass == 0 ? "Warrior" : newClass == 1 ? "Archer" : "Priest") << endl;
    }
};

void PlayerTraining(int playerId, int numDays, Member team[], int& success, int& failure) {
    srand(playerId);
    for (int i = 0; i < 3; ++i) {
        team[i].OutputStatus();
    }
    cout << "------------------------------------------------------------" << endl;

    for (int day = 1; day <= numDays; ++day) {
        cout << "Day " << day << endl;
        int choice;
        bool validChoice = false;
        do {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill): ";
            cin >> choice;
            if (choice == 0) {
                cout << "------------------------------------------------------------" << endl;
                return;
            } else if (choice == 9) {
                int memberIndex;
                cout << "Transfer (0-Sandy, 1-Robin, 2-Alice): ";
                cin >> memberIndex;
                team[memberIndex].Transfer();
            } else if (choice >= 1 && choice <= 4) {
                validChoice = true;
            }
        } while (!validChoice);

        for (int i = 0; i < 3; ++i) {
            if (team[i].MemberTraining(choice - 1)) {
                success++;
            } else {
                failure++;
            }
        }

        cout << "------------------------------------------------------------" << endl;
    }
    for (int i = 0; i < 3; ++i) {
        team[i].OutputStatus();
    }
}

int main() {
    Member team[3] { {"Sandy",0,20,10,10}, {"Robin",1,16,12,8}, {"Alice",2,12,6,10} };
    int playerID, numDays, success = 0, failure = 0;
    cout << "Player ID and Days for Training: ";
    cin >> playerID >> numDays;
    PlayerTraining(playerID, numDays, team, success, failure);
    cout << "Training Success/Failure: " << success << "/" << failure << endl;
    return 0;
}