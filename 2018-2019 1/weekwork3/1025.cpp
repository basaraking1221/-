#include <iostream>
#include <algorithm>
using namespace std;
struct flo
{
    int beg,en;
};
bool comp(flo a,flo b)
{
    return a.beg<b.beg;
}
int main()
{
    int n;
    flo a[20001];
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        scanf("%d%d",&a[i].beg,&a[i].en);
    sort(a,a + n,comp);
    int ans = 0;
    for (int now = 0;now < n;now++)
        if ( (a[now].en >= a[now + 1].beg) && (a[now].en < a[now + 1].en) )
        a[now + 1].beg = a[now].beg;
        else if ( (a[now].en >= a[now + 1].beg) && (a[now].en >= a[now + 1].en) )
        {
            a[now + 1].beg = a[now].beg;a[now + 1].en = a[now].en;
        }
        else
        ans += a[now].en - a[now].beg;
    ans += a[n - 1].en - a[n - 1].beg;
    printf("%d",ans);
    return 0;
}