#include <iostream>
#include <queue>
#include <cmath>
using namespace std;

struct poi
{
    int x,y;
    poi() {}
    poi(int xx,int yy):x(xx),y(yy) {}
};

int m,n;
int h[510][510];
int flagNum = 0;
poi flag[250010];

bool reach(int height)
{
    queue<poi> a;
    bool vis[510][510] = {0};
    vis[flag[0].x][flag[0].y] = 1;
    a.push(flag[0]);
    while (!a.empty())
    {
        int xx = a.front().x;int yy = a.front().y;
        a.pop();
        if (xx >= 1)
        if ((abs(h[xx][yy] - h[xx - 1][yy]) <= height)&&(!vis[xx - 1][yy]))
        {
            vis[xx - 1][yy] = 1;
            a.push(poi(xx - 1,yy));
        }
        if (xx + 1 < m)
        if ((abs(h[xx][yy] - h[xx + 1][yy]) <= height)&&(!vis[xx + 1][yy]))
        {
            vis[xx + 1][yy] = 1;
            a.push(poi(xx + 1,yy));
        }
        if (yy >= 1)
        if ((abs(h[xx][yy] - h[xx][yy - 1]) <= height)&&(!vis[xx][yy - 1]))
        {
            vis[xx][yy - 1] = 1;
            a.push(poi(xx,yy - 1));
        }
        if (yy + 1 < n)
        if ((abs(h[xx][yy] - h[xx][yy + 1]) <= height)&&(!vis[xx][yy + 1]))
        {
            vis[xx][yy + 1] = 1;
            a.push(poi(xx,yy + 1));
        }
    }
    for (int i = 0;i < flagNum;i++)
        if (!vis[flag[i].x][flag[i].y])
            return false;
    return true;
}

int main()
{    
    int temp;
    int max = 0;int min = 2147483647;
    scanf("%d%d",&m,&n);
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            {
                scanf("%d",&h[i][j]);
                if (h[i][j] > max) max = h[i][j];
                if (h[i][j] < min) min = h[i][j];
            }
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            {
                scanf("%d",&temp);
                if (temp)
                {
                    flag[flagNum].x = i;flag[flagNum].y = j;
                    flagNum++;
                }
            }
    int l = 0;int r = max - min;
    int mid;
    while(r - l > 1)
    {
        mid = (l + r) / 2;
        if (reach(mid)) r = mid;
        else l = mid;
    }
    if (reach(l)) printf("%d",l);
    else printf("%d",r);
    return 0;
}