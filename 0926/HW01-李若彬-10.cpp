#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    float a;
    cin>>a;
    float b=a*60*60;
    int h = b/3600;
    int m = (b-h*3600)/60;
    float s = round((b-h*3600-m*60)*100)/100;
    int s1 = s;
    cout<<h<<"h"<<m<<"m"<<s1<<"s"<<endl;
    return 0;
}
