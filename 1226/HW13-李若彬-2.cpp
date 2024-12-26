#include <iostream>
//此处填写预编译命令
#include <fstream>
#include <sstream>
class Actor;
void InputActors(const std::string& file, Actor actors[]);
#define NUM 20
using namespace std;

class Team;
class Actor{
    //此处填写友元声明
    friend class Team;
    friend void InputActors(const string& file, Actor actors[]);
    friend ostream& operator<<(ostream& os, const Team& team);
private:
    int id;
    char name[10];
    int hp, atk, def;
    bool heal;
public:
    Actor():id(0),heal(false){}
};
class Team{
    //此处填写友元声明
    friend ostream& operator<<(ostream& os, const Team& team);
private:
    Actor *leftActors;
    Actor *rightActors;
    int threshold;
public:
    Team(Actor left[], Actor right[], int t):leftActors(left), rightActors(right), threshold(t){}
};
int main() {
    Actor eastActor[NUM], westActor[NUM];
    int threshold;
    //此处定义一个对象
    ofstream fout("team.txt", ios::out);
    InputActors("actors_east.txt", eastActor);
    InputActors("actors_west.txt", westActor);
    cout << "Threshold (1-100): "; cin >> threshold;
    Team team(eastActor, westActor, threshold);
    fout << team;
    fout.close();
    return 0;
}

//此处定义若干个函数
void InputActors(const string& file, Actor actors[]) {
    ifstream fin(file, ios::in);
    if (!fin.is_open()) {
        cerr << "Error opening file." << endl;
        return;
    }

    string header;
    getline(fin, header); // Read and ignore the header line

    string line;
    int i = 0;
    while (getline(fin, line)) {
        stringstream ss(line);
        ss >> actors[i].id >> actors[i].name >> actors[i].hp >> actors[i].atk >> actors[i].def;
        string healer;
        if (ss >> healer) {
            actors[i].heal = (healer == "healer");
        } else {
            actors[i].heal = false;
        }
        i++;
    }
    fin.close();
}

ostream& operator<<(ostream& os, const Team& team) {
    auto meetsConditions = [](const Actor& actor, int threshold) {
        int count = 0;
        if (actor.hp > threshold) count++;
        if (actor.atk > threshold / 3) count++;
        if (actor.def > threshold / 3) count++;
        if (actor.heal) count++;
        return count >= 3;
    };
    os << "ID\tName\tHP\tATK\tDEF" << endl;

    int k = 1;
    int i = 0;
    while (team.leftActors[i].id) {
        if (meetsConditions(team.leftActors[i], team.threshold)) {
            os << k << "\t" << team.leftActors[i].name << "\t" << team.leftActors[i].hp << "\t" << team.leftActors[i].atk << "\t" << team.leftActors[i].def << "\t" << (team.leftActors[i].heal ? "healer\t" : "") << endl;
            k++;
        }
        i++;

    }
    int j = 0;
    while (team.rightActors[j].id) {
        if (meetsConditions(team.rightActors[j], team.threshold)) {
            os << k << "\t" << team.rightActors[j].name << "\t" << team.rightActors[j].hp << "\t" << team.rightActors[j].atk << "\t" << team.rightActors[j].def << "\t" << (team.rightActors[j].heal ? "healer\t" : "") << endl;
            k++;
        }
        j++;
    }
    return os;
}

