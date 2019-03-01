#include <stdio.h>
int main(){
    int k;
    scanf("%d",&k);
    double sum = 0;
    int now = 1;
    while(sum <= k) sum += 1.0/(now++);
    printf("%d",now - 1);
    return 0;
}