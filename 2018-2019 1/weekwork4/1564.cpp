#include <iostream>
using namespace std;
int v[10][10];
bool visit[10][10];
int sx,sy,ex,ey;
int ans;
void dfs(int x,int y,int nowValue,int stat)
{
    int stepValue;
    if ((x == ex)&&(y == ey))
        {
            if (nowValue < ans) ans = nowValue;
            return;
        }
    visit[x][y] = 1;
    if (x<5)
    if (!visit[x+1][y])
    {
        stepValue = v[x+1][y] * stat;
        dfs(x+1,y,nowValue + stepValue,stepValue % 4 + 1);
    }
    if (x>0)
    if (!visit[x-1][y])
    {
        stepValue = v[x-1][y] * stat;
        dfs(x-1,y,nowValue + stepValue,stepValue % 4 + 1);
    }
    if (y<5)
    if (!visit[x][y+1])
    {
        stepValue = v[x][y+1] * stat;
        dfs(x,y+1,nowValue + stepValue,stepValue % 4 + 1);
    }
    if (y>0)
    if (!visit[x][y-1])
    {
        stepValue = v[x][y-1] * stat;
        dfs(x,y-1,nowValue + stepValue,stepValue % 4 + 1);
    }
    visit[x][y] = 0;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
    {
        ans = 1000000000;
        for (int i = 0;i < 6;i++)
            for (int j = 0;j < 6;j++)
                {scanf("%d",&v[i][j]);visit[i][j] = 0;}
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        dfs(sx,sy,0,1);
        printf("%d\n",ans);
    }
    return 0;
}