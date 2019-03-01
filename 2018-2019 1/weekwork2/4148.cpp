#include <iostream>
using namespace std;
int ans[1001][1001] = {0};
int main()
{
    const int c[2][4]={{3,0,1,2},{1,2,3,0}};
    int n,m,p;

    int x = 1;int y = 1;
    int now = 0;
    int direction = 0;

    scanf("%d%d%d", &n, &m, &p);
    if (p == 0) {x = 0; direction = 1;}
    else y = 0;
    while (now < n * m)
    {
        switch(direction)
        {
        case 0: ans[x][++y] = ++now;
                if ((ans[x][y+1] != 0)||(y+1 > m)) direction = c[p][direction];
                break;
        case 1: ans[++x][y] = ++now;
                if ((ans[x+1][y] != 0)||(x+1 > n)) direction = c[p][direction];
                break;
        case 2: ans[x][--y] = ++now;
                if ((ans[x][y-1] != 0)||(y-1 < 1)) direction = c[p][direction];
                break;
        case 3: ans[--x][y] = ++now;
                if ((ans[x-1][y] != 0)||(x-1 < 1)) direction = c[p][direction];
                break;
        default : break;
        }
    }

    for (int i = 1;i <= n;i++)
    {
        for (int j = 1;j <= m;j++) printf("%d ", ans[i][j]);
        printf("\n");
    }
    return 0;
}