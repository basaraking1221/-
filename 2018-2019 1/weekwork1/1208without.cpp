#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    double r,a;
    double maxs=0;
    while (cin>>r>>a)
    {
        double s=acos((double)a/r)*r*r-sqrt(r*r-a*a)*a;
        if (s>maxs) maxs=s;
    }
    maxs=(int)(maxs*100+0.5)/100.0;
    printf("%.2lf",maxs);
    return 0;
}