#include <stdio.h>
struct inf{
    int a,b,g,k;
};
int main(){
    int n;
    inf cur[10005];
    int x,y;
    scanf("%d",&n);
    for (int i = 1;i <= n;i++)
        scanf("%d%d%d%d",&cur[i].a,&cur[i].b,&cur[i].g,&cur[i].k);
    scanf("%d%d",&x,&y);
    for (int i = n;i > 0;i--)
        if (cur[i].a <= x && cur[i].b <= y && cur[i].a + cur[i].g >= x && cur[i].b + cur[i].k >= y){
            printf("%d",i);
            return 0;
        }
    printf("-1");
    return 0;
}