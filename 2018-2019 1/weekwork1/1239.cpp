#include <iostream>
using namespace std;
double calc(int sala);
int main()
{
    int sala;
    double tax;

    scanf("%d",&sala);
    tax=calc(sala);
    printf("%d",(int)tax);
    return 0;
}
double calc(int s)
{
    double re;
    s-=3500;
    if (s<0) return 0;
    if (s<1500) return (double)s*0.03;
    if (s<4500) return (double)(s-1500)*0.1+45.0;
    if (s<9000) return (double)(s-4500)*0.2+345.0;
    if (s<35000) return (double)(s-9000)*0.25+1245.0;
    if (s<55000) return (double)(s-35000)*0.3+7745.0;
    if (s<80000) return (double)(s-55000)*0.35+13745.0;
    return (double)(s-80000)*0.45+22495.0;
}