#include <iostream>
#include <cassert>
using namespace std;
class Cell{
    // 此处需填写代码
private:
    int size;
    static int resource;
public:
    Cell(int init_size);
    Cell(const Cell &c);
    ~Cell();
    void grow();
    void grow() const;
    bool kill(Cell*& cell) const;
    int get_size();
    static int get_resource();
};
int main()
{
    int init_size, id=1, max_id=0;
    Cell *cells[100] = {0};

    cout << "Initial Cell Size: ";
    cin >> init_size;
    const Cell *init_cell = new const Cell(init_size);
    cout << "Initial Cell is born, remaining resource = " << Cell::get_resource() << endl;
    cells[0] = new Cell(*init_cell);
    cout << "Cell 0 is born, remaining resource = " << Cell::get_resource() << endl;
    while(true) {
        // 此处需填写代码
        init_cell->grow();if(Cell::get_resource() < 0 || id > 100){
            break;
        }
        cout << "Initial Cell grows, remaining resource = " << Cell::get_resource() << endl;
        int old_id = id;
        for (int i = 0; i < old_id; ++i) {
            if (cells[i]) {
                cells[i]->grow();
                if(Cell::get_resource() < 0 || id > 100){
                    break;
                }
                cout << "Cell " << i << " grows, remaining resource = " << Cell::get_resource() << endl;
                if (cells[i]->get_size() > 5 && id < 100) {
                    int new_size = cells[i]->get_size() / 2;
                    cells[id] = new Cell(new_size);
                    if(Cell::get_resource() < 0 || id > 100){
                        break;
                    }
                    cout << "Cell " << id << " is born, remaining resource = " << Cell::get_resource() << endl;
                    ++id;
                    if(id > 100) break;
                }
            }
        }
        if(Cell::get_resource() <= 0 || id > 100){
            break;
        }
        for(int i = 0; i < id; ++i){
            if(cells[i] && cells[i]->get_size() > 10){
                max_id = i;
                break;
            }
        }
        for(int i = 0; i < id; ++i){
            if(cells[i] && cells[max_id] && cells[i]->get_size() > cells[max_id]->get_size() && cells[max_id]->get_size() > 10){
                max_id = i;
            }
        }
        if(init_cell->kill(cells[max_id])){
            assert(cells[max_id] == NULL);
            // 此处需填写代码
            cout << "Cell " << max_id << " is killed, remaining resource = " << Cell::get_resource() << endl;
        }
    }
    return 0; //不要求在 main 函数结束前释放所有动态分配的内存空间
}
// 此处需填写代码（Cell 类的实现）
int Cell::resource = 500;
Cell::Cell(int init_size){
    size = init_size;
    resource -= size;
}
Cell::Cell(const Cell &c){
    size = c.size / 2;
    resource -= size;
}
Cell::~Cell(){
    resource += size;
}
void Cell::grow(){
    resource--;
    size++;
}
void Cell::grow() const{
    resource--;
}
bool Cell::kill(Cell*& cell) const{
    if (cell != nullptr && cell->get_size() > 10) {
        delete cell;
        cell = nullptr;
        return true;
    }
    return false;
}
int Cell::get_size(){
    return size;
}
int Cell::get_resource(){
    return resource;
}