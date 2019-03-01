#include <iostream>
#include <queue>
using namespace std;
struct poi
{
    bool vis;
    int step[2];
};
struct po
{
    int x,y;
    po(int xx,int yy):x(xx),y(yy){}
};
poi det[1010][1010];
int n,m;
int deal(int startx,int starty,int s)
{
    queue<po> a;
    a.push(po(startx,starty));
    while (!a.empty())
    {
        int xx = a.front().x;
        int yy = a.front().y;
        if (xx + 1 < m)
        if (!det[xx + 1][yy].vis)
        {
            det[xx + 1][yy].vis = 1;
            det[xx + 1][yy].step[s] = det[xx][yy].step[s] + 1;
            a.push(po(xx + 1,yy));
        }
        if (xx - 1 >= 0)
        if (!det[xx - 1][yy].vis)
        {
            det[xx - 1][yy].vis = 1;
            det[xx - 1][yy].step[s] = det[xx][yy].step[s] + 1;
            a.push(po(xx - 1,yy));
        }
        if (yy + 1 < n)
        if (!det[xx][yy + 1].vis)
        {
            det[xx][yy + 1].vis = 1;
            det[xx][yy + 1].step[s] = det[xx][yy].step[s] + 1;
            a.push(po(xx,yy + 1));
        }
        if (yy - 1 >= 0)
        if (!det[xx][yy - 1].vis)
        {
            det[xx][yy - 1].vis = 1;
            det[xx][yy - 1].step[s] = det[xx][yy].step[s] + 1;
            a.push(po(xx,yy - 1));
        }
        a.pop();
    }
}
short stat[1010][1010];
int tox[1000000],toy[1000000];
int main()
{
    int startx,starty,endx,endy;
    int tonum = -1;
    int ans = 1000000000;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            {
                scanf("%d",&stat[i][j]);
                switch (stat[i][j])
                {
                    case 0:det[i][j].vis = 0;break;
                    case 1:det[i][j].vis = 1;break;
                    case 2:startx = i;starty = j;det[i][j].vis = 0;break;
                    case 3:endx = i;endy = j;det[i][j].vis = 0;break;
                    case 4:tonum++;tox[tonum] = i;toy[tonum] = j;det[i][j].vis = 0;break;
                    default:break;
                }
                det[i][j].step[0] = det[i][j].step[1] = -1;
            }
    det[startx][starty].step[0] = det[endx][endy].step[1] = 0;
    deal(startx,starty,0);
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            if (stat[i][j] != 1) det[i][j].vis = 0;
    deal(endx,endy,1);
    for (int i = 0;i <= tonum;i++)
        if ((det[tox[i]][toy[i]].step[0] > 0)&&(det[tox[i]][toy[i]].step[1] > 0)
            &&((det[tox[i]][toy[i]].step[0] + det[tox[i]][toy[i]].step[1]) < ans))
            ans = det[tox[i]][toy[i]].step[0] + det[tox[i]][toy[i]].step[1];
    printf("%d",ans);
    return 0;
}