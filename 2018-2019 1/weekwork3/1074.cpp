#include <iostream>
using namespace std;
int height[1300][1300] = {0};
void tryit(int m);
bool judge(int k, int m);
int ans = 0;
int n;
int main()
{
    int m;

    scanf("%d%d",&n,&m);
    getchar();
    for (int i = 1;i <= n;i++)
    {
        char temp;
        for (int j = 0;j < m;j++)
            {
                temp = getchar();
                if (temp == '-') height[i][j] = height[i-1][j] + 1;
                else height[i][j] = 0;
                
            }
        tryit(i);
        getchar();
    }
    printf("%d",ans);
    return 0;

}
void tryit(int m)
{
    int r = 0;
    for (int i = 0;i < n; i++)
        if (r < height[m][i]) r = height[m][i];
    int l = 0;
    int mid = (l + r) / 2;
    while (r - l > 1)
        {
            mid = (l + r) / 2;
            if (judge(mid, m)) l = mid;
                else r = mid;
        }
    int a = 0;
    if (judge(r, m)) a = r;
    else a = l;
    if (ans < 2*a*a) ans = 2 * a * a;
    return;
}
bool judge(int k, int m)
{
    if (k == 0) return 1;
    int cou = 0;
    for (int i = 0;i < n;i++)
        if (height[m][i] < k) cou = 0;
        else
        {
            cou++;
            if (cou >= 2 * k) return 1;
        }
    return 0;
}