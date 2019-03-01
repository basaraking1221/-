#include <stdio.h>
int main(){
    int n;
    int k[105];
    int first = -1,last;
    scanf("%d",&n);
    for (int i = n;i >= 0;i--){
        scanf("%d",&k[i]);
        if (first == -1)
            if (k[i] != 0) first = i;
        if (k[i]) last = i;
    }
    for (int i = first;i >= last;i--){
        if (i == first){
            if (k[i] == 1) printf("x^%d",i);
            else if (k[i] == -1) printf("-x^%d",i);
            else printf("%dx^%d",k[i],i);
            continue;
        }
        if (i == 0){
            if (k[i] > 0) printf("+%d",k[i]);
            else printf("%d",k[i]);
            continue; 
        }
        if (i == 1){
            if (!k[i]) continue;
            else if (k[i] == 1) printf("+x");
            else if (k[i] == -1) printf("-x");
            else if (k[i] > 0) printf("+%dx",k[i]);
            else printf("%dx",k[i]);
            continue;
        }
        if (!k[i]) continue;
        else if (k[i] == 1) printf("+x^%d",i);
        else if (k[i] == -1) printf("-x^%d",i);
        else if (k[i] > 0) printf("+%dx^%d",k[i],i);
        else printf("%dx^%d",k[i],i);
    }
    return 0; 
}