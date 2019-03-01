#include <iostream>
#include <algorithm>
using namespace std;
long long tri(int* ord,int n)
{
    long long re = 0;
    for (int i = 0;i < n - 1;i++)
        for (int j = i + 1;j < n;j++)
            if (ord[j] < ord[i]) re++;
    return re;
}
int main()
{
    int n;
    long long a[15][15];
    long long ans = 0;
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < n;j++)
            scanf("%lld",&a[i][j]);
    int ord[15] = {0,1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    do
    {
        long long temp = tri(ord,n);
        if (temp%2 == 0) temp = 1;
        else temp = -1;
        for (int i = 0;i < n;i++) temp *= a[i][ord[i]];
        ans += temp;
    }
    while (next_permutation(ord,ord + n));
    printf("%lld",ans);
    return 0;
}