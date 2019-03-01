#include <iostream>
#include <algorithm>
using namespace std;
int main ()
{
    int n;
    int b;
    int a[101] = {0};
    int cut_value[101] = {0};
    int odd = 0,even = 0;
    int cutn = 0;
    int inn = 0;
    
    scanf("%d%d", &n, &b);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d", &a[i]);
        if (inn)
        {
            if (a[i] > a[i - 1])
                cut_value[cutn] = a[i] - a[i - 1];
            else cut_value[cutn] = a[i - 1] - a[i];
            inn = 0;
        }
        if ((a[i]%2)!=0) odd++; else even++;
        if ((odd == even)&&(i != n)) {++cutn;inn = 1;}
    }
    sort(cut_value + 1,cut_value + 1 + cutn);
    int ans = 0;
    for (int i = 1;i <= cutn;i++)
    {
        b -= cut_value[i];
        if (b >= 0)
        {
            ans++;
            continue;
        }
        break;
    }
    printf("%d",ans);
    return 0;
}