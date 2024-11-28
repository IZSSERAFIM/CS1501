#include <iostream>
#include <cstring>
#define HEAL_VALID 20
#define HEAL_EFFECT 10
using namespace std;
struct Actor
{
    char name[10];
    // ①此处需填写多行代码
    int hp, atk, def;
    bool heal;
};

Actor& GetPlayer(char [], int);
Actor& GetEnemy(int);
// ②此处需填写一行代码
void Action(Actor& user, Actor& target, int act);

int main()
{
    char name[10];
    int money, act;
    cout << "What's your name? (No more than 9 letters) ";
    cin >> name;
    cout << "How much will you pay for the game? $";
    cin >> money;
    Actor& player = GetPlayer(name, money);
    Actor& enemy = GetEnemy(money);
    cout << "===== " << player.name << " vs " << enemy.name << " =====" << endl;
    if (money < 1) { cout << "You Lose!" << endl; return 0; }
    for (int i = 1; i <= 10; ++i) {
        cout << "Round " << i << endl;
        // ③此处需填写三行代码
        cout << player.name << "'s act (1-attack; 2-heal; otherwise-wait): ";
        cin >> act;
        if(!player.heal && act == 2) act = 3;
        Action(player, enemy, act);
        if (enemy.hp < 10 && enemy.heal) act = 2;
        else act = 1;
        Action(enemy, player, act);
        if (player.hp > 0 && enemy.hp <= 0) {
            cout << "You Win!" << endl; return 0;
        } else if (enemy.hp > 0 && player.hp <= 0) {
            cout << "You Lose!" << endl; return 0;
        } else if (player.hp <= 0 && enemy.hp <= 0) {
            cout << "End of Game with Draw." << endl; return 0;
        }
        cout << player.name << "'s remaining HP: " << player.hp << endl;
        cout << enemy.name << "'s remaining HP: " << enemy.hp << endl;
        cout << "---------------------" << endl;
    }
    cout << "End of Game with Draw." << endl;

    // ④此处需填写两行代码
    delete &player;
    delete &enemy;
    return 0;
}

Actor& GetPlayer(char name[], int m) {
    // ⑤此处需填写多行代码
    Actor *player = new Actor;
    strcpy(player->name, name);
    player->heal = m >= HEAL_VALID;
    player->hp = m;
    player->atk = m/2;
    player->def = m/3;
    cout<<"Welcome to this game "<<player->name<<"!"<<endl;
    cout<<"Your status: HP"<<player->hp<<", ATK"<<player->atk<<", DEF"<<player->def<<endl;
    cout<<"You can attack the enemy and heal yourself."<<endl;
    return *player;
}

Actor& GetEnemy(int m) {
    int choice;
    cout << "Input a digit to choose your enemy (0 for Wolf, or otherwise Slime): ";
    cin >> choice;
    // ⑥此处需填写多行代码
    Actor *enemy = new Actor;
    if(choice == 0) {
        strcpy(enemy->name, "Wolf");
        enemy->heal = false;
        enemy->hp = 25 + m/4;
        enemy->atk = 9 + m/6;
        enemy->def = 6 + m/6;
        enemy->heal = false;
        cout << "Your enemy " << enemy->name << ": HP" << enemy->hp << ", ATK" << enemy->atk << ", DEF" << enemy->def << endl;
        return *enemy;
    }
    strcpy(enemy->name, "Slime");
    enemy->heal = false;
    enemy->hp = 20 + m/5;
    enemy->atk = 8 + m/6;
    enemy->def = 7 + m/6;
    enemy->heal = true;
    cout << "Your enemy " << enemy->name << ": HP" << enemy->hp << ", ATK" << enemy->atk << ", DEF" << enemy->def << endl;
    // ⑦此处需填写一行代码
    return *enemy;
}

// ⑧此处需填写一行代码
void Action(Actor& user, Actor& target, int act)
{
    if(act == 1) {
        cout << user.name << " attacks " << target.name << "!" << endl;
        int damage = user.atk - target.def;
        if(damage < 0) damage = 0;
        target.hp -= damage;
    }else if(act == 2) {
        cout << user.name << " does self-healing!" << endl;
        user.hp += HEAL_EFFECT;
    }else cout << user.name << " is waiting..." << endl;
}
