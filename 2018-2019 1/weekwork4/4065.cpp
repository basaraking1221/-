#include <iostream>
#include <queue>
using namespace std;
int main()
{
    int n,m;
    int stat[305][305];
    bool vis[305][305];
    int startx,starty,endx,endy;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            scanf("%d",&stat[i][j]);
            switch (stat[i][j])
            {
                case 0:vis[i][j] = 1;break;
                case 1:vis[i][j] = 0;break;
                case 2:startx = i;starty = j;vis[i][j] = 0;break;
                case 3:endx = i;endy = j;vis[i][j] = 0;break;
                case 4:
                default:break;
            }
        }
}