#include <iostream>
using namespace std;

class Cell {
    friend istream &operator>>(istream &, Cell &);
protected:
    int size;
    static int resource;
public:
    int get_size() const {return size;}
    bool grow();
};

// 此处需填写代码（定义一个基于 Cell 类的派生类）
class NewCell : public Cell {
private:
    int id;
    static int counter;
public:
    NewCell() : id(counter++) { size = 0; }
    bool grow();
    void set_size(int size);
    bool operator=(Cell& parent);
    bool operator=(NewCell& parent);
    friend ostream& operator<<(ostream& os, NewCell& cell);
};

int main(){
    Cell init_cell;
    NewCell cells[100];
    int id=1, max_id=0, max_size;
    cout << "Initial Cell Size: ";
    cin >> init_cell;
    if(cells[0] = init_cell) return 0;
    while(true) {
        if(init_cell.grow()) return 0;
        int thisRound = id;
        for(int i=0;i<thisRound;++i){
            if(cells[i].get_size() == 0) continue;
            if(cells[i].grow()) return 0;
            if(cells[i].get_size() > 5){
                if(cells[id] = cells[i]) return 0;
                if(cells[id].get_size() > cells[max_id].get_size()) max_id = id;
                id++;
                if(id>=100) return 0;
            }
        }
        if(cells[max_id].get_size() > 10) {
            cout << cells[max_id];
            max_id = 0, max_size = 0;
            for(int i=0;i<id;++i){
                if(cells[i].get_size() > max_size) {max_size = cells[i].get_size(); max_id = i;}
            }
        }
    }
    return 0;
}
// 此处需填写代码（Cell 类及其派生类的实现，以及它们的运算符重载函数的定义）
int NewCell::counter = 0;
int Cell::resource = 500;

bool Cell::grow() {
    if (resource <= 0) return true;
    resource--;
    return false;
}

istream &operator>>(istream &is, Cell &cell) {
    is >> cell.size;
    Cell::resource -= cell.size;
    return is;
}

bool NewCell::grow() {
    if (resource <= 0) return true;
    size++;
    resource--;
    cout << "Cell " << id << " grows, remaining resource = " << resource << endl;
    return false;
}

ostream& operator<<(ostream& os, NewCell& cell) {
    NewCell::resource += cell.size;
    cell.set_size(0);
    os << "Cell " << cell.id << " dies, remaining resource = " << NewCell::resource << endl;
    return os;
}

bool NewCell::operator=(Cell& parent) {
    cout << "Initial Cell grows, remaining resource = " << resource << endl;
    this->size = parent.get_size() / 2;
    resource -= this->size;
    if (resource <= 0) {
        return true;
    }
    cout << "Cell " << id << " is born, remaining resource = " << resource << endl;
    return false;
}

bool NewCell::operator=(NewCell& parent) {
    this->size = parent.size / 2;
    resource -= this->size;
    if (resource <= 0) {
        return true;
    }
    cout << "Cell " << id << " is born, remaining resource = " << resource << endl;
    return false;
}

void NewCell::set_size(int size) {
    this->size = size;
}