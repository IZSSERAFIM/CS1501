#include <iostream>
#include <cstdlib>

using namespace std;

const int NUM_STATUS = 4, NUM_MEMBER = 3;
const char statusName[NUM_STATUS][10] = {"HP", "ATK", "DEF", "Skill"};

void PlayerTraining(int hp[], int atk[], int def[], bool skills[][2], int successes[], int failures[], int numDays,
                    int playerId);
bool MemberTraining(int& hp, int& atk, int& def, bool skills[], int memberIndex, int trainingType);
void OutputStatus(int hp, int atk, int def, const bool skills[], int memberIndex);

int main()
{
    int playerId, numDays;
    cout << "Player ID and Days for Training: ";
    cin >> playerId >> numDays;

    int hp[NUM_MEMBER] = {20, 16, 12};
    int atk[NUM_MEMBER] = {10, 12, 6};
    int def[NUM_MEMBER] = {10, 8, 10};
    bool skills[NUM_MEMBER][2] = {{false, false}, {false, false}, {false, false}};
    int successfulTrainings[NUM_MEMBER] = {0, 0, 0};
    int failedTrainings[NUM_MEMBER] = {0, 0, 0};

    PlayerTraining(hp, atk, def, skills, successfulTrainings, failedTrainings, numDays, playerId);

    for (int i = 0; i < NUM_MEMBER - 1; ++i)
    {
        for (int j = 0; j < NUM_MEMBER - i - 1; ++j)
        {
            if (successfulTrainings[j] < successfulTrainings[j + 1])
            {
                swap(successfulTrainings[j], successfulTrainings[j + 1]);
                swap(failedTrainings[j], failedTrainings[j + 1]);
                swap(hp[j], hp[j + 1]);
                swap(atk[j], atk[j + 1]);
                swap(def[j], def[j + 1]);
                swap(skills[j], skills[j + 1]);
            }
        }
    }

    int totalSuccesses = 0, totalFailures = 0;
    for (int i = 0; i < NUM_MEMBER; ++i)
    {
        totalSuccesses += successfulTrainings[i];
        totalFailures += failedTrainings[i];
        OutputStatus(hp[i], atk[i], def[i], skills[i], i);
    }
    cout << "Training Success/Failure: " << totalSuccesses << "/" << totalFailures << endl;

    return 0;
}

void PlayerTraining(int hp[], int atk[], int def[], bool skills[][2], int successes[], int failures[], int numDays,
                    int playerId)
{
    static const char member[NUM_MEMBER][10] = {"Warrior", "Archer", "Priest"};
    static const char skillName[NUM_MEMBER][2][10] = {{"Taunt", ""}, {"Focus", ""}, {"Heal", "Cure"}};
    static const double rate[NUM_MEMBER][NUM_STATUS] = {
        {0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}
    };

    srand(playerId);
    for (int i = 0; i < NUM_MEMBER; ++i)
    {
        OutputStatus(hp[i], atk[i], def[i], skills[i], i);
    }
    cout << "------------------------------------------------------------" << endl;

    for (int day = 1; day <= numDays; ++day)
    {
        cout << "Day " << day << endl;
        int choice;
        do
        {
            cout << "Select the training plan (1-HP, 2-ATK, 3-DEF, 4-Skill): ";
            cin >> choice;
            if (choice == 0)
            {
                cout << "------------------------------------------------------------" << endl;
                return;
            }
        }
        while (choice < 1 || choice > 4);

        switch (choice)
        {
        case 1: cout << "HP Training:\n";
            break;
        case 2: cout << "ATK Training:\n";
            break;
        case 3: cout << "DEF Training:\n";
            break;
        case 4: cout << "Skill Training:\n";
            break;
        default: break;
        }

        for (int i = 0; i < NUM_MEMBER; ++i)
        {
            if (MemberTraining(hp[i], atk[i], def[i], skills[i], i, choice - 1))
            {
                successes[i]++;
            }
            else
            {
                failures[i]++;
            }
        }

        cout << "------------------------------------------------------------" << endl;
    }
}

bool MemberTraining(int& hp, int& atk, int& def, bool skills[], int memberIndex, int trainingType)
{
    static const double rate[NUM_MEMBER][NUM_STATUS] = {
        {0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}
    };
    static const char member[NUM_MEMBER][10] = {"Warrior", "Archer", "Priest"};

    double successRate = rate[memberIndex][trainingType];
    bool success = ((double)rand() / RAND_MAX) <= successRate;

    if (success)
    {
        switch (trainingType)
        {
        case 0: hp += 1;
            cout << member[memberIndex] << " Success, HP+1\n";
            break;
        case 1: atk += 1;
            cout << member[memberIndex] << " Success, ATK+1\n";
            break;
        case 2: def += 1;
            cout << member[memberIndex] << " Success, DEF+1\n";
            break;
        case 3:
            if (!skills[0] && memberIndex == 0)
            {
                // Warrior learns Taunt
                skills[0] = true;
                cout << member[memberIndex] << " Success, Skill \"Taunt\" is learned\n";
            }
            else if (!skills[0] && memberIndex == 1)
            {
                // Archer learns Focus
                skills[0] = true;
                cout << member[memberIndex] << " Success, Skill \"Focus\" is learned\n";
            }
            else if (memberIndex == 2)
            {
                // Priest learns Heal then Cure
                if (!skills[0])
                {
                    skills[0] = true;
                    cout << member[memberIndex] << " Success, Skill \"Heal\" is learned\n";
                }
                else if (!skills[1])
                {
                    skills[1] = true;
                    cout << member[memberIndex] << " Success, Skill \"Cure\" is learned\n";
                }
                else
                {
                    cout << member[memberIndex] << " Success, No more skills to learn\n";
                }
            }
            else
            {
                cout << member[memberIndex] << " Success, No more skills to learn\n";
            }
            break;
        }
    }
    else
    {
        cout << member[memberIndex] << " Failure\n";
    }
    return success;
}

void OutputStatus(int hp, int atk, int def, const bool skills[], int memberIndex)
{
    static const char member[NUM_MEMBER][10] = {"Warrior", "Archer", "Priest"};
    static const char skillName[NUM_MEMBER][2][10] = {{"Taunt", ""}, {"Focus", ""}, {"Heal", "Cure"}};

    cout << member[memberIndex] << " Status: "
        << "HP " << hp << ", "
        << "ATK " << atk << ", "
        << "DEF " << def << ", "
        << "Skill: ";
    bool hasSkill = false;
    if (skills[0])
    {
        cout << skillName[memberIndex][0];
        hasSkill = true;
    }
    if (skills[1])
    {
        if (hasSkill) cout << ", ";
        cout << skillName[memberIndex][1];
    }
    if (!hasSkill) cout << "None";
    cout << endl;
}
