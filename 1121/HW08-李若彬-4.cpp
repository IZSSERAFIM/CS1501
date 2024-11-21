#include <iostream>
#include <cstdlib>
#include <cstdint>

using namespace std;

const int NUM_STATUS = 4, NUM_MEMBER = 3;
const int HP = 0, ATK = 1, DEF = 2, SKILL = 3;
const int TAUNT = 1, FOCUS = 2, HEAL = 4, CURE = 8;

void PlayerTraining(int hp[], int atk[], int def[], int skills[], int successes[], int failures[], int numDays,
                    int playerId);
bool MemberTraining(int64_t& status, int trainingType);
void OutputStatus(const int64_t& status);
void OutputName(const int memberIndex);

int main()
{
    int playerId, numDays;
    cout << "Player ID and Days for Training: ";
    cin >> playerId >> numDays;

    int hp[NUM_MEMBER] = {20, 16, 12};
    int atk[NUM_MEMBER] = {10, 12, 6};
    int def[NUM_MEMBER] = {10, 8, 10};
    int skills[NUM_MEMBER] = {0, 0, 0};
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
        int64_t status = (static_cast<int64_t>(i) << 32) | (hp[i] << 24) | (atk[i] << 16) | (def[i] << 8) | skills[i];
        OutputStatus(status);
    }
    cout << "Training Success/Failure: " << totalSuccesses << "/" << totalFailures << endl;

    return 0;
}

void PlayerTraining(int hp[], int atk[], int def[], int skills[], int successes[], int failures[], int numDays,
                    int playerId)
{
    static const double rate[NUM_MEMBER][NUM_STATUS] = {
        {0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}
    };

    srand(playerId);
    for (int i = 0; i < NUM_MEMBER; ++i)
    {
        int64_t status = (static_cast<int64_t>(i) << 32) | (hp[i] << 24) | (atk[i] << 16) | (def[i] << 8) | skills[i];
        OutputStatus(status);
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
            int64_t status = (static_cast<int64_t>(i) << 32) | (hp[i] << 24) | (atk[i] << 16) | (def[i] << 8) | skills[
                i];
            if (MemberTraining(status, choice - 1))
            {
                successes[i]++;
            }
            else
            {
                failures[i]++;
            }
            hp[i] = (status >> 24) & 0xFF;
            atk[i] = (status >> 16) & 0xFF;
            def[i] = (status >> 8) & 0xFF;
            skills[i] = status & 0xFF;
        }

        cout << "------------------------------------------------------------" << endl;
    }
}

bool MemberTraining(int64_t& status, int trainingType)
{
    static const double rate[NUM_MEMBER][NUM_STATUS] = {
        {0.8, 0.6, 0.8, 0.2}, {0.6, 0.8, 0.6, 0.3}, {0.6, 0.6, 0.6, 0.4}
    };
    static const int memberSkills[NUM_MEMBER] = {TAUNT, FOCUS, HEAL | CURE};

    int memberIndex = (status >> 32) & 0xFF;
    int hp = (status >> 24) & 0xFF;
    int atk = (status >> 16) & 0xFF;
    int def = (status >> 8) & 0xFF;
    int skills = status & 0xFF;

    double successRate = rate[memberIndex][trainingType];
    bool success = ((double)rand() / RAND_MAX) <= successRate;

    if (success)
    {
        switch (trainingType)
        {
        case HP: hp += 1;
            OutputName(memberIndex);
            cout << " Success, HP+1\n";
            break;
        case ATK: atk += 1;
            OutputName(memberIndex);
            cout << " Success, ATK+1\n";
            break;
        case DEF: def += 1;
            OutputName(memberIndex);
            cout << " Success, DEF+1\n";
            break;
        case SKILL:
            if (memberIndex == 0)
            {
                // Warrior learns Taunt
                if (!(skills & TAUNT))
                {
                    skills |= TAUNT;
                    cout << "Warrior Success, Skill \"Taunt\" is learned\n";
                }
                else
                {
                    cout << "Warrior Success, No more skills to learn\n";
                }
            }
            else if (memberIndex == 1)
            {
                // Archer learns Focus
                if (!(skills & FOCUS))
                {
                    skills |= FOCUS;
                    cout << "Archer Success, Skill \"Focus\" is learned\n";
                }
                else
                {
                    cout << "Archer Success, No more skills to learn\n";
                }
            }
            else if (memberIndex == 2)
            {
                // Priest learns Heal then Cure
                if (!(skills & HEAL))
                {
                    skills |= HEAL;
                    cout << "Priest Success, Skill \"Heal\" is learned\n";
                }
                else if (!(skills & CURE))
                {
                    skills |= CURE;
                    cout << "Priest Success, Skill \"Cure\" is learned\n";
                }
                else
                {
                    cout << "Priest Success, No more skills to learn\n";
                }
            }
            break;
        }
    }
    else
    {
        OutputName(memberIndex);
        cout << " Failure\n";
    }

    status = (hp << 24) | (atk << 16) | (def << 8) | skills;
    return success;
}

void OutputStatus(const int64_t& status)
{
    int memberIndex = (status >> 32) & 0xFF;
    int hp = (status >> 24) & 0xFF;
    int atk = (status >> 16) & 0xFF;
    int def = (status >> 8) & 0xFF;
    int skills = status & 0xFF;

    OutputName(memberIndex);

    cout << " Status: "
        << "HP " << hp << ", "
        << "ATK " << atk << ", "
        << "DEF " << def << ", "
        << "Skill: ";
    if (skills & TAUNT) cout << "Taunt ";
    if (skills & FOCUS) cout << "Focus ";
    if (skills & HEAL) cout << "Heal ";
    if (skills & CURE) cout << "Cure ";
    if (skills == 0) cout << "None";
    cout << endl;
}

void OutputName(const int memberIndex)
{
    switch (memberIndex)
    {
    case 0: cout << "Warrior";
        break;
    case 1: cout << "Archer";
        break;
    case 2: cout << "Priest";
        break;
    default: break;
    }
}
