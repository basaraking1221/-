#include <iostream>
#include <algorithm>
using namespace std;
int a[250010];
int main()
{
    int m,n;
    int num;
    long long v;

    scanf("%d%d",&m,&n);
    num = m * n;
    for (int i =0;i < m;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&a[i * n + j]);
    sort(a + 1,a + 1 + num);
    scanf("%lld",&v);
  
    int h1 = a[1];double h2;
    n = 1;
    long long temp = v;
    while (temp > 0)
    {
        if (n == num) break;
        if (a[n + 1]==a[n]) {n++;continue;}
        temp -= (a[n + 1] - h1) * n;n++;h1 = a[n];
    }
    if (temp == 0) n--;
    if (temp < 0)
    {
        temp += (h1 - a[n - 1]) * (n - 1);
        n--;h1 = a[n];
    }
    h2 = (double)h1 + (double)temp / ((double)n);
    double ans = n*100.0/num;
    printf("%.2f ", h2);
    printf("%.2f", ans);
    return 0;
}