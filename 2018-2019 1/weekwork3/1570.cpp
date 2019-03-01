#include <iostream>
#include <algorithm>
struct like
{
    int y,num,ans;
};
bool comp1(like a,like b)
{
    return a.y<b.y;
}
bool comp2(like a,like b)
{
    return a.num<b.num;
}
using namespace std;
int main()
{
    int n,t;
    int x[100000];
    like l[100000];
    scanf("%d%d",&n,&t);
    for (int i = 0;i < n;i++) scanf("%d",&x[i]);
    for (int i = 0;i < t;i++)
    {
        scanf("%d",&l[i].y);
        l[i].num = i;
    }
    sort(x,x + n);
    sort(l,l + t,comp1);
    int now = 0;
    for (int i = 0;i < n;i++)
    {
        if (x[i]<=l[now].y) continue;
        while (x[i] > l[now].y)
        {
            l[now].ans = n - i;
            now++;
            if (now > t) break;
        }
        if (now > t) break;
    }
    sort(l, l + t, comp2);
    for (int i = 0;i < t;i++) printf("%d\n",l[i].ans);
    return 0;
}