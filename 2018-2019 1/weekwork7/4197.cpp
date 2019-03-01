#include <iostream>
#include <stdio.h>
using namespace std;
long long d[2002],e[2002],a[2002],b[2002];
long long x;
int main(){
    int n,m;
    long long temp;
    int num = -1;
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++){
        scanf("%lld",&temp);
        d[i] = d[i - 1] + temp;
    }
    for (int i = 1;i <= m;i++){
        scanf("%lld",&temp);
        e[i] = e[i - 1] + temp;
    }
    scanf("%lld",&x);
    int head = 1;int tail = 1;
    for (int i = 1;i <= n;i++)
        for (int j = i;j <= n;j++)
        if ((a[j - i + 1] > d[j] - d[i - 1])||(a[j - i + 1] == 0))
            a[j - i + 1] = d[j] - d[i - 1];
    for (int i = 1;i <= m;i++)
        for (int j = i;j <= n;j++)
        if ((b[j - i + 1] > e[j] - e[i - 1])||(b[j - i + 1] == 0))
            b[j - i + 1] = e[j] - e[j - 1];
    for (int i = 1;i <= n;i++){
        if (a[i] > x) continue;
        int temp = x / a[i];
        for (int j = 1;j <= m;j++)
            if (b[j] < temp)
            if (i * j > num) num = i * j;
    }
    return 0;
}