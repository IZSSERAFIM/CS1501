#include <iostream>
using namespace std;

// Julian 函数，转换 year 和 day 为日期字符串，如果非法则返回 NULL
const char* Julian(int year, int day) {
    // 判断是否是闰年
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

    // 每个月的天数（平年）
    int daysInMonth[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

    // 如果是闰年，更新二月的天数为29
    if (isLeap) {
        daysInMonth[1] = 29;
    }

    // 检查 day 的合法性
    int totalDays = isLeap ? 366 : 365;  // 根据闰年或平年确定总天数
    if (day < 1 || day > totalDays) {
        return NULL;  // 如果 day 超出范围，返回 NULL
    }

    // 查找对应的月份和日期
    int month = 0;  // 月份索引，初始为1月
    while (day > daysInMonth[month]) {
        day -= daysInMonth[month];  // 减去当前月份的天数
        month++;  // 移动到下一个月
    }

    // 月份名称数组
    const char* months[] = { "Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec" };

    // 返回格式化的日期字符串
    static char result[20];  // 静态字符数组，用于存储结果
    sprintf(result, "%s %d", months[month], day);  // 格式化日期
    return result;  // 返回日期字符串
}

int main() {
    int year, day;

    // 输入年份和天数
    cout << "Please input year and day: ";
    cin >> year >> day;

    // 调用 Julian 函数
    const char* date = Julian(year, day);

    // 根据返回值输出结果
    if (date == NULL) {
        cout << "N/A" << endl;  // 如果返回 NULL，输出 N/A
    } else {
        cout << "Output: " << date << endl;  // 否则输出日期
    }

    return 0;
}