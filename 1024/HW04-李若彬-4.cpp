#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <map>
#include <algorithm>

using namespace std;

struct Character {
    string profession;
    int hp;
    int atk;
    int def;
    vector<string> skills;
    map<string, double> successRates;
    int successfulTrainings;

    Character() : successfulTrainings(0) {}
};

class TrainingSystem {
private:
    vector<Character> characters;
    int playerId;
    int day;

    // 获取职业可学习的技能列表
    vector<string> getProfessionSkills(const string& profession) const {
        if (profession == "Warrior") return {"Taunt"};
        if (profession == "Archer") return {"Focus"};
        if (profession == "Priest") return {"Heal", "Cure"};
        return {};
    }

    // 初始化角色成功率
    map<string, double> initializeSuccessRates(const string& profession) const {
        if (profession == "Warrior") {
            return {{"HP", 0.8}, {"ATK", 0.6}, {"DEF", 0.8}, {"Skill", 0.2}};
        } else if (profession == "Archer") {
            return {{"HP", 0.6}, {"ATK", 0.8}, {"DEF", 0.6}, {"Skill", 0.3}};
        } else if (profession == "Priest") {
            return {{"HP", 0.6}, {"ATK", 0.6}, {"DEF", 0.6}, {"Skill", 0.4}};
        }
        return {};
    }

    // 检查训练是否成功
    bool isTrainingSuccessful(const Character& character, const string& trainingType) const {
        double rate = character.successRates.at(trainingType);
        return (static_cast<double>(rand()) / RAND_MAX) <= rate;
    }

public:
    TrainingSystem(int id) : playerId(id), day(1) {
        srand(id);

        // 初始化三个角色
        vector<pair<string, tuple<int, int, int>>> initStats = {
            {"Warrior", {20, 10, 10}},
            {"Archer", {16, 12, 8}},
            {"Priest", {12, 6, 10}}
        };

        for (const auto& [prof, stats] : initStats) {
            auto [hp, atk, def] = stats;
            Character character;
            character.profession = prof;
            character.hp = hp;
            character.atk = atk;
            character.def = def;
            character.successRates = initializeSuccessRates(prof);
            character.skills = {};
            characters.push_back(character);
        }
    }

    void printStatus() const {
        vector<Character> sortedCharacters = characters;

        std::sort(sortedCharacters.begin(), sortedCharacters.end(), [](const Character& a, const Character& b) {
            return a.successfulTrainings > b.successfulTrainings;
        });

        for (const auto& character : sortedCharacters) {
            cout << character.profession << " Status: HP "
                 << character.hp
                 << ", ATK " << character.atk
                 << ", DEF " << character.def
                 << "; Skill: ";
            if (character.skills.empty()) {
                cout << "None";
            } else {
                for (size_t i = 0; i < character.skills.size(); ++i) {
                    if (i > 0) cout << ", ";
                    cout << character.skills[i];
                }
            }
            cout << endl;
        }
    }

    void train(int choice) {
        for (auto& character : characters) {
            cout << character.profession << " ";

            string trainingType;
            bool success = false;
            switch(choice) {
                case 1: {
                    trainingType = "HP";
                    success = isTrainingSuccessful(character, trainingType);
                    if (success) {
                        character.hp += 1;
                        cout << "Success, HP+1" << endl;
                    } else {
                        cout << "Failure" << endl;
                    }
                    break;
                }
                case 2: {
                    trainingType = "ATK";
                    success = isTrainingSuccessful(character, trainingType);
                    if (success) {
                        character.atk += 1;
                        cout << "Success, ATK+1" << endl;
                    } else {
                        cout << "Failure" << endl;
                    }
                    break;
                }
                case 3: {
                    trainingType = "DEF";
                    success = isTrainingSuccessful(character, trainingType);
                    if (success) {
                        character.def += 1;
                        cout << "Success, DEF+1" << endl;
                    } else {
                        cout << "Failure" << endl;
                    }
                    break;
                }
                case 4: {
                    vector<string> availableSkills = getProfessionSkills(character.profession);
                    if (character.skills.size() < availableSkills.size()) {
                        success = isTrainingSuccessful(character, "Skill");
                        if (success) {
                            string newSkill = availableSkills[character.skills.size()];
                            character.skills.push_back(newSkill);
                            cout << "Success, Skill \"" << newSkill << "\" is learned" << endl;
                        } else {
                            cout << "Failure" << endl;
                        }
                    } else {
                        cout << "Success, No more skills to learn" << endl;
                    }
                    break;
                }
            }
            if (success) {
                character.successfulTrainings++;
            }
        }

        cout << "------------------------------------------------------------" << endl;
        day++;
    }

    bool isTrainingComplete() const {
        return day > 10;
    }

    int getDay() const {
        return day;
    }
};

int main() {
    int playerId;
    cout << "Player ID: ";
    cin >> playerId;

    TrainingSystem trainer(playerId);
    trainer.printStatus();
    cout << "------------------------------------------------------------" << endl;

    while (!trainer.isTrainingComplete()) {
        int choice;
        cout << "Day " << trainer.getDay() << endl;

        // 循环直到用户输入有效的选择或输入0
        do {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill): ";
            cin >> choice;
            if (choice == 0) {
                cout << "------------------------------------------------------------" << endl;
                trainer.printStatus();
                return 0;
            }
        } while (choice < 1 || choice > 4);

        trainer.train(choice);
    }

    trainer.printStatus();
    return 0;
}