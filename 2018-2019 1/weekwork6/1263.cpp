#include <iostream>
using namespace std;

const int ca[4] = {1,0,1,0};
const int cb[4] = {1,0,0,1};
int ans[204][102][102] = {0};
int main(){
    int m,n;
    int v[102][102];
    
    scanf("%d%d",&m,&n);
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++)
            scanf("%d",&v[i][j]);
    ans[0][1][1] = v[1][1];
    ans[1][1][2] = v[1][1] + v[1][2] + v[2][1];
    for (int t = 1;t < m + n - 2;t++)
    for (int a = max(1,t + 2 - n);a <= min(t,m - 1);a++)
    for (int b = a + 1;b <= min(t + 1,m);b++)
    for (int k = 0;k < 4;k++)
        if (b - cb[k] != a - ca[k])
            if ((a - ca[k] > 0) && (b - cb[k] > 0))
                if (ans[t][a][b] < (ans[t - 1][a - ca[k]][b - cb[k]] + v[a][t - a + 2]
                + v[b][t - b + 2]))
                    ans[t][a][b] = ans[t - 1][a - ca[k]][b - cb[k]] + v[a][t - a + 2]
                    + v[b][t - b + 2];
    printf("%d",ans[m + n - 3][m - 1][m] + v[m][n]);
    return 0;
}