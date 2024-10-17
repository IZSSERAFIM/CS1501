#include <iostream>
#include <cstdlib>

using namespace std;

// 玩家结构体，包含HP，ATK，DEF和技能
struct Player {
    int id;
    int hp;
    int atk;
    int def;
    string skill;
};

// 随机返回训练是否成功
bool isTrainingSuccessful(int choice) {
    switch (choice) {
        case 1:
        case 2:
        case 3:
            return static_cast<float>(rand()) / RAND_MAX <= 0.8;
        case 4:
            return static_cast<float>(rand()) / RAND_MAX <= 0.2;
        default:
            return false;
    }
}

int main() {
    Player player;
    player.id = 0; // 玩家ID

    cout << "Player ID: ";
    cin >> player.id;
    srand(player.id); // 使用id初始化随机数种子

    player.hp = rand() % 13 + 12; // HP随机值在[12, 24]之间
    player.atk = rand() % 9 + 8; // ATK随机值在[8, 16]之间
    player.def = rand() % 5 + 4; // DEF随机值在[4, 8]之间
    player.skill = "None"; // 初始技能为None

    cout << "Player Status: HP " << player.hp << ", ATK " << player.atk << ", DEF " << player.def << ", Skill: " <<
            player.skill << endl;
    cout << "------------------------------------------------------------" << endl;

    int day = 1;
    while (day <= 10) {
        // 输出当前天数
        cout << "Day " << day << endl;
        cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill): ";

        int choice;
        cin >> choice; // 用户选择训练计划
        goto start;


    restart: // 重新输入标签
        {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill): ";
            cin >> choice;
        }

    start:
        if (choice < 0 || choice > 4) {
            goto restart;
        }
        // 根据选择进行训练
        if (choice == 1) {
            // HP 训练
            cout << "HP Training: ";
            if (isTrainingSuccessful(choice)) {
                cout << "Success, HP+1" << endl;
                player.hp += 1;
            } else {
                cout << "Failure" << endl;
            }
        } else if (choice == 2) {
            // ATK 训练
            cout << "ATK Training: ";
            if (isTrainingSuccessful(choice)) {
                cout << "Success, ATK+1" << endl;
                player.atk += 1;
            } else {
                cout << "Failure" << endl;
            }
        } else if (choice == 3) {
            // DEF 训练
            cout << "DEF Training: ";
            if (isTrainingSuccessful(choice)) {
                cout << "Success, DEF+1" << endl;
                player.def += 1;
            } else {
                cout << "Failure" << endl;
            }
        } else if (choice == 4) {
            // 技能训练
            if (player.skill == "None") {
                cout << "Skill Training: ";
                if (isTrainingSuccessful(choice)) {
                    cout << "Success, Skill \"Heal\" is learned" << endl;
                    player.skill = "Heal";
                } else {
                    cout << "Failure" << endl;
                }
            } else {
                goto restart;
            }
        } else if (choice == 0) {
            // 如果选择为0，结束训练
            cout << "------------------------------------------------------------" << endl;
            break;
        }

        cout << "------------------------------------------------------------" << endl;

        day++; // 增加天数
    }
    // 输出当前状态
    cout << "Player Status: HP " << player.hp << ", ATK " << player.atk << ", DEF " << player.def << "; Skill: " <<
            player.skill << endl;

    return 0;
}
