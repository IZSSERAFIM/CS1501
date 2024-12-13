#include <iostream>
using namespace std;
//填写代码，只有一行
class Cell;
class Virus{
    int life;
public:
    Virus(int x):life(x){}
    //填写代码，只有一行
    void eat(Cell &c, int amount);
    bool time_pass(){life --; return (life?true:false);}
};
class Cell{
    //填写代码，只有一行
    friend void Virus::eat(Cell &c, int amount);
private:
    int size;
public:
    Cell(int x):size(x){}
    void time_pass(){if(size) size ++;}
};
int main() {
    int cell, virus, amount, cnt;
    cout << "Input cell, virus, amount: "; cin >> cell >> virus >> amount;
    Cell c(cell); Virus v(virus);
    for(cnt=0; ; cnt++){
        v.eat(c, amount);
        if( ! v.time_pass() ) break;
        c.time_pass();
    }
    cout << "Output: Time = " << cnt << endl;
    return 0;
}
//填写代码，定义一个成员函数
void Virus::eat(Cell &c, int amount)
{
    if(c.size < amount) amount = c.size;
    c.size -= amount;
    this->life += amount;
}