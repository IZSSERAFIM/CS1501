#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    const int r = 6371;
    double x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    x1*=M_PI/180;
    y1*=M_PI/180;
    x2*=M_PI/180;
    y2*=M_PI/180;
    double a = r*acos(cos(y1)*cos(y2)*cos(x1-x2)+sin(y1)*sin(y2));
    cout <<static_cast<int>(round(a))<<endl;
    return 0;
}
