#include <iostream>
using namespace std;
int a[200010];
int n,k;
bool check(int m)
{
    int round = 1;
    int now = 0;
    int left = k;
    while(!( (round == 2) && (now == k)))
    {
        if (left == 0) return 1;
        if (a[now] <= m) left--;
        else left = k;
        now++;
        if (now == n)
        {
            now = 0;
            round++;
        }
    }
    return 0;
}
int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    int l = 1;
    int r = 1000000001;
    while(r - l > 1)
    {
        int mid = (r + l) / 2;
        if (check(mid)) r = mid;
        else l = mid;
    }
    if (check(l)) printf("%d",l);
    else printf("%d",r);
    return 0;
}