#include <stdio.h>
const double fir = 0.4463;
const double sec = 0.4663;
const double thi = 0.5663;
int main(){
    int all;
    double ans = 0;
    scanf("%d",&all);
    if (all <= 150) ans = all * fir;
    else if (all <= 400) ans = 150 * fir + (all - 150) * sec;
    else ans = 150 * fir + 250 * sec + (all - 400) * thi;
    printf("%.1lf",ans);
    return 0;
}