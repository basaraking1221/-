#include <stdio.h>
int temp[1002];
int a[1002];
void change(int &x,int &y){
    int c = x;
    x = y;
    y = c;
}
void sort(int l,int r){
    if (l == r) return;
    if (l + 1 == r){
        if (a[l] > a[r]) change(a[l],a[r]);
        return;
    }
    int mid = (l + r) / 2;
    sort(l,mid);
    sort(mid + 1,r);
    int pl = l,pr = mid + 1,now = l;
    while(pl <= mid && pr <= r)
        if (a[pl] < a[pr]) temp[now++] = a[pl++];
        else temp[now++] = a[pr++];
    if (pl > mid)
        while (now <= r) temp[now++] = a[pr++];
    else while(now <= r) temp[now++] = a[pl++];
    for (int i = l;i <= r;i++) a[i] = temp[i];
}
int main(){
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) scanf("%d",&a[i]);
    sort(0,n - 1);
    int ans = 1;
    for (int i = 1;i < n;i++)
        if (a[i] != a[i - 1]) ans++;
    printf("%d\n",ans);
    printf("%d",a[0]);
    for (int i = 1;i < n;i++)
        if (a[i] != a[i - 1]) printf(" %d",a[i]);
    return 0;
}