#include <iostream>
#include <queue>
using namespace std;
struct po
{
    int x,y;
    po(int xx,int yy):x(xx),y(yy){}
};
bool l[500][500];
int num = 0;
int n,m;
void deal(int x,int y)
{
    queue<po> a;
    a.push(po(x,y));
    while (!a.empty())
    {
        int xx = a.front().x;
        int yy = a.front().y;
        if (xx + 1 < n)
        if (!l[xx + 1][yy])
        {
            l[xx + 1][yy] = 1;
            a.push(po(xx + 1,yy));
        }
        if (xx - 1 >= 0)
        if (!l[xx - 1][yy])
        {
            l[xx - 1][yy] = 1;
            a.push(po(xx - 1,yy));
        }
        if (yy + 1 < m)
        if (!l[xx][yy + 1])
        {
            l[xx][yy + 1] = 1;
            a.push(po(xx,yy + 1));
        }
        if (yy - 1 >= 0)
        if (!l[xx][yy - 1])
        {
            l[xx][yy - 1] = 1;
            a.push(po(xx,yy - 1));
        }
        a.pop();
    }
}
int main()
{
    int temp;
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        {
            scanf("%d",&temp);
            if (temp == 0) l[i][j] = 0;
            else l[i][j] = 1;
        }
    for (int i = 0;i < n;i++)
        for (int j = 0;j < m;j++)
        if (!l[i][j])
            {deal(i,j);num++;}
    printf("%d",num);
    return 0;
}