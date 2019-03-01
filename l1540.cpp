#include <stdio.h>
int main(){
    int m,n;
    int alr[101];
    int fir = 0,now,num = 0;
    bool has[1001] = {0};
    int ans = 0;
    scanf("%d%d",&m,&n);
    for (int i = 0;i < n;i++){
        scanf("%d",&now);
        if (!has[now]){
            ans++;
            if (num != m){
                alr[fir + num++] = now;
                has[now] = true;
            }
            else{
                has[alr[fir]] = false;
                has[now] = true;
                alr[fir] = now;
                fir++;
                if (fir >= m) fir = 0;
            }
        }
    }
    printf("%d",ans);
    return 0;
}