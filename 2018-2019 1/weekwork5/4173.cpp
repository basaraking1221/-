#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;
int x[4000010],y[4000010];
int fx,fy;int tx,ty;
int ans = 2e9;
bool judge(int x1,int y1,int x2,int y2,int s){
    int x = fx + x1 - x2;
    int y = fy + y1 - y2;
    if ((abs(x - tx) + abs(y - ty)) <= s && ((s - (abs(x - tx) + abs(y - ty))) % 2 == 0 )) return 1;
    else return 0;
}
int main()
{
    int n;
    char temp;
    scanf("%d",&n);
    x[0] = y[0] = 0;
    for (int i = 1;i <= n;i++)
    {
        cin>>temp;
        switch(temp)
        {
            case 'U':x[i] = x[i-1];y[i] = y[i - 1] + 1;break;
            case 'D':x[i] = x[i-1];y[i] = y[i - 1] - 1;break;
            case 'L':x[i] = x[i-1] - 1;y[i] = y[i - 1];break;
            case 'R':x[i] = x[i-1] + 1;y[i] = y[i - 1];break;
            default:printf("WTF");break;
        }
    }
    scanf("%d%d",&tx,&ty);
    fx = x[n];fy = y[n];
    int r = 0;
    for (int i = 0;i <= n;i++)
    {
        while (!judge(x[i],y[i],x[r],y[r],r - i)){
            r++;
            if (r == n + 1) break;
        }
        if (r == n + 1) break;
        if (r - i < ans) ans = r - i;
    }
    if (ans < 2e9)
        printf("%d",ans);
    else printf("-1");
    return 0;
}