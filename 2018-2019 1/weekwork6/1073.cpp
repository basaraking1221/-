#include <iostream>
using namespace std;
int ans[200][250],v[250];
int max(int a,int b){
    if (a > b) return a;
    return b;
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++){
        scanf( "%d", &v[i]);
        v[i+n] = v[i];
    }
    for(int i = 1;i < n;i++)
        for(int r = 1; r < n * 2 + 1 - i;r++)
            for(int k = r; k < r + i;k++)
                ans[r][i + r] = max(ans[r][i + r],
                ans[r][k] + ans[k + 1][i + r] + v[r]*v[k + 1]*v[i + r + 1]);
    int outp = 0;
    for(int i = 1;i <= n;i++)
        outp = max(outp,ans[i][i+n-1]);
    printf("%d",outp);
    return 0;
}
