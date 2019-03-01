#include <iostream>
using namespace std;
const int siz = 100005;
int a[siz],b[siz],p[siz];
int s[siz];
void doit(int n,int r){
    int l = 1;
    int mid;
    while (r - l > 1){
        mid = (l + r) / 2;
        if (n > s[mid]) l = mid;
        else r = mid;
    }
    if (s[l] > n) s[l] = n;
    else s[r] = n;
    return;
}
int main(){
    int n;
    int l = 1;
    scanf("%d",&n);
    for (int i = 0;i < n;i++)
        scanf("%d",&a[i]);
    for (int i = 0;i < n;i++){
        scanf("%d",&b[i]);
        p[b[i]] = i;
        s[i] = siz;
    }
    for (int i = 0;i < n;i++) a[i] = p[a[i]];
    s[1] = a[0];
    for (int i = 1;i < n;i++){
        if (a[i] > s[l])
            s[++l] = a[i];
        else doit(a[i],l);
    }
    printf("%d",l);
    return 0;
}