#include <iostream>
using namespace std;
void doit();
int main()
{
    int t;
    scanf("%d",&t);
    for (int i = 0;i < t;i++) doit();
    return 0;
}
int x[1000000],y[1000000];
int a[1001][1001];
void doit()
{
    int m,n,p,q;
    int num = -1;
    int temp;
    scanf("%d%d%d%d",&m,&n,&p,&q);
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
            scanf("%d",&a[i][j]);
    for (int i = 0;i < p;i++)
        for (int j = 0;j < q;j++)
        {
            scanf("%d",&temp);
            if (temp)
            {
                num++;
                x[num] = i;y[num] = j;
            }
        }
    for (int i = 0;i < m;i++)
        for (int j = 0;j < n;j++)
        if (a[i][j]==0) continue;
        else
        {
            for (int k = 0;k <= num;k++)
            if ((i + x[k] - x[0] >= m)||(j + y[k] - y[0] >= n)||(a[i + x[k] - x[0]][j + y[k] - y[0]] == 0))
                {printf("No\n");return;}
            else a[i + x[k] - x[0]][j + y[k] - y[0]] = 0;
        }
    printf("Yes\n");
    return;
}