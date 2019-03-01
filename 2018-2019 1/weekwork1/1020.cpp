#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    int s[40]={0},t[40]={0};
    int num=0;
    int test=2;
    int nn;

    scanf("%d",&n);
    nn=n;
    while (n!=1)
    {
        if (n%test==0)
        {
            num++;
            s[num]=test;
            while(n%test==0)
            {
                t[num]++;
                n/=test;
            }
        }
        if (test>2) test+=2; else test++;
    }

    printf("%d=",nn);
    for (int i=1;i<=num;i++)
    printf("%d(%d)",s[i],t[i]);
    return 0;
}