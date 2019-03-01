#include <iostream>
using namespace std;
void doit()
{
    int n,m;
    int tempn,tempa;
    int ans = 0;
    int mo[5010] = {0};
    scanf("%d%d",&n,&m);
    tempa = 0;
    for (int i = 0;i < n;i++)
    {
        scanf("%d",&tempn);
        tempa += tempn;
        mo[tempa % m]++;
    }
    if (mo[0]) ans += mo[0] * (mo[0] + 1) / 2;
    for (int i = 1;i < m;i++)
    if (mo[i] > 1) ans += mo[i] * (mo[i] - 1) / 2;
    printf("%d\n",ans);
}
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < t;i++) doit();
    return 0;
}