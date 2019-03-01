#include <iostream>
using namespace std;
int main()
{
    int from[100010],tt[100010],a[100010],l[100010];
    int n,m,k;
    bool hav[100010] = {0};
    scanf("%d%d%d",&n,&m,&k);
    for (int i = 0;i < m;i++)
        scanf("%d%d%d",&from[i],&tt[i],&l[i]);
    for (int i = 0;i < k;i++)
        {
            scanf("%d",&a[i]);
            hav[a[i]] = 1;
        }
    int ans = 1000000010;
    for (int i = 0;i < m;i++)
        if (( (hav[from[i]])&&(!hav[tt[i]]) ) || ( (!hav[from[i]])&&(hav[tt[i]]) ))
            if (l[i] < ans) ans = l[i];
    if (ans == 1000000010) printf("-1");
    else printf("%d",ans);
    return 0;
}
