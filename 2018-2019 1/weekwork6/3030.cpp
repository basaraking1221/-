#include <iostream>
using namespace std;
int mas(int a,int b){
    if (a > b) return a;
    return b;
}
int main(){
    int t,m;
    int ans[101][1005] = {0};
    int c[101] = {0},v[101] = {0};
    scanf("%d%d",&t,&m);
    for (int i = 1;i <= m;i++)
        scanf("%d%d",&c[i],&v[i]);
    for (int i = 1;i <= m;i++)
        for (int j = 0;j <= t;j++){
            if (j - c[i] < 0)
                ans[i][j] = ans[i - 1][j];
            else ans[i][j] = mas(ans[i - 1][j],ans[i - 1][j - c[i]] + v[i]);
        }
    int aa = 0;
    for (int i = 0;i <= t;i++)
        if (aa < ans[m][i]) aa = ans[m][i];
    printf("%d",aa);
    return 0;
}