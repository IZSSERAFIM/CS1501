#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class SavingAccount {
private:
    int accountNumber;
    double balance;
    static double monthlyRate;
    static int nextAccountNumber;
public:
    // 构造函数
    SavingAccount() : accountNumber(nextAccountNumber++), balance(0) {}
    static void setRate(double rate) {
        monthlyRate = rate;
    }
    void deposit(double amount) {
        balance += amount;
    }
    static void nextMonth(SavingAccount* sa) {
        for (int i = 0; i < nextAccountNumber - 1; ++i) {
            sa[i].balance += sa[i].balance * monthlyRate;
            // 四舍五入到0.01元
            sa[i].balance = round(sa[i].balance * 100) / 100;
        }
    }
    void show() const {
        cout << "Account No. " << accountNumber << ": " << fixed << setprecision(2) << balance << endl;
    }
};

// 初始化静态成员变量
double SavingAccount::monthlyRate = 0;
int SavingAccount::nextAccountNumber = 1;

int main() {
    int num, index;
    double rate, amount;
    cout << "Number of Accounts: ";
    cin >> num;
    SavingAccount *sa = new SavingAccount[num];

    while (true) {
        cout << "Input the monthly rate: ";
        cin >> rate;
        SavingAccount::setRate(rate); // 设置本月利率
        cout << "Input the index, amount for deposit: ";
        cin >> index >> amount;
        if (index < 0 || index >= num) break;
        sa[index].deposit(amount); // 存款
        SavingAccount::nextMonth(sa); // 时间经过一个月
    }
    cout << "Input the index for output: ";
    cin >> index;
    sa[index].show(); // 显示账户的账号和当前金额
    delete[] sa;
    return 0;
}