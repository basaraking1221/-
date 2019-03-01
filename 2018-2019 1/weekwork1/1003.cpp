/*it's simply a floodfill problem and we solve it by a queue*/
#include <iostream>
#include <cstring>
using namespace std;
struct note
{
    int x,y,time;
};

int n[102][102];
int quel=0;
int ans=0;
note que[10002];

void detect(int x, int y, int ti);

int main()
{
    int l;
    int front=1;
    memset(n, -1, sizeof(n));

    scanf("%d", &l);
    for (int i = 1;i <= l;i++)
        for (int j = 1;j <= l;j++)
            {
                scanf("%d", &n[i][j]);
                if (n[i][j] == 1)
                {
                    quel++;
                    que[quel].x = i; que[quel].y = j; que[quel].time=0;
                }
            }
            
    while (quel >= front)
    {
        detect(que[front].x+1, que[front].y, que[front].time);
        detect(que[front].x-1, que[front].y, que[front].time);
        detect(que[front].x, que[front].y+1, que[front].time);
        detect(que[front].x, que[front].y-1, que[front].time);
        front++;
    }

    printf("%d", ans);
    return 0;
}

void detect(int x, int y, int ti)
{
    if ((n[x][y]==-1)||(n[x][y]==1)||(n[x][y]==2)) return;
    if (n[x][y]==0)
    {
        n[x][y]=-1;
        quel++;
        que[quel].x = x; que[quel].y = y; que[quel].time = ti+1;
    }
    if ((ti+1) > ans) ans=ti+1;
    return;
}