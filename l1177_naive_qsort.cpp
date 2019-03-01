#include <stdio.h>
void change(int *a,int *b){
    int c = *a;
    *a = *b;
    *b = c;
}
void qsort(int *a,int *b){
    if (a == b) return;
    if (a + 1 == b){
        if (*b < *a) change(a,b);
        return;
    }
    int *i = a + 1,*j = b;
    while(i != j){
        while(*a <= *j && i < j) j--;
        while(*i <= *a && i < j) i++;
        change(i,j);
    }
    if (*i < *a)
        change(a,i);
    qsort(a,i - 1);
    qsort(i,b);
}
int main(){
    int n;
    int a[100002];
    scanf("%d",&n);
    for (int i = 0;i < n;i++) scanf("%d",&a[i]);
    qsort(a,a + n - 1);
    for (int i = 0;i < n;i++) printf("%d ",a[i]);
    return 0;
}