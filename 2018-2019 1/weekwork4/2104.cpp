#include <iostream>
#include <queue>
using namespace std;
struct poi
{
    bool vis;
    int step;
};
struct po
{
    int x,y;
    po(int xx,int yy):x(xx),y(yy){}
};
poi det[1010][1010];
int main()
{
    queue<po> a;
    int x,y;
    int n;
    scanf("%d%d%d",&x,&y,&n);
    for (int i = 0;i < (x + 500);i++)
        for (int j = 0;j < (y + 500);j++)
            {det[i][j].step = 0;det[i][j].vis = 0;}
    for (int i = 0;i < n;i++)
    {
        int tx,ty;
        scanf("%d%d",&tx,&ty);
        det[tx + 500][ty + 500].vis = 1;
    }
    a.push(po(500,500));
    while (!a.empty())
    {
        int xx = a.front().x;
        int yy = a.front().y;
        if ((xx == (x + 500))&&(yy == (y + 500)))
        {
            printf("%d",det[xx][yy].step);
            return 0;
        }
        if (!det[xx + 1][yy].vis)
        {
            det[xx + 1][yy].vis = 1;
            det[xx + 1][yy].step = det[xx][yy].step + 1;
            a.push(po(xx + 1,yy));
        }
        if (!det[xx - 1][yy].vis)
        {
            det[xx - 1][yy].vis = 1;
            det[xx - 1][yy].step = det[xx][yy].step + 1;
            a.push(po(xx - 1,yy));
        }
        if (!det[xx][yy + 1].vis)
        {
            det[xx][yy + 1].vis = 1;
            det[xx][yy + 1].step = det[xx][yy].step + 1;
            a.push(po(xx,yy + 1));
        }
        if (!det[xx][yy - 1].vis)
        {
            det[xx][yy - 1].vis = 1;
            det[xx][yy - 1].step = det[xx][yy].step + 1;
            a.push(po(xx,yy - 1));
        }
        a.pop();
    }
}