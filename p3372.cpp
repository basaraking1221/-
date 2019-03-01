#include <stdio.h>
int n,m;
long long tree[400005];
long long sequent[100005];
void buildtree(int a,int l,int r){
    if (l == r){
        tree[a] = sequent[l];
        return;
    }
    buildtree(2 * a,l,(l + r) / 2);
    buildtree(2 * a + 1,(l + r) / 2 + 1,r);
    tree[a] = tree[2 * a] + tree[1 + 2 * a];
}
int sum(int a,int b,int l,int r,int p){
    if (a == l && b == r){
        return tree[p];
    }
    int mid = (a + b) / 2;
    if (mid >= r) return sum(a,mid,l,r,2 * p);
    if (mid < l) return sum(mid + 1,b,l,r,2 * p + 1);
    return sum(a,mid,l,mid,2 * p) + sum(mid + 1,b,mid + 1,r,2 * p + 1);
}
void increase(int a,int b,int l,int r,int p,long long x){
    tree[p] += x * (r - l + 1);
    if (l == r) return;
    int mid = (a + b) / 2;
    if (mid >= r) increase(a,mid,l,r,2 * p,x);
    else if (mid < l) increase(mid + 1,b,l,r,2 * p + 1,x);
    else{
        increase(a,mid,l,mid,2 * p,x);
        increase(mid + 1,b,mid + 1,r,2 * p + 1,x);
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for (int i = 1;i <= n;i++) scanf("%lld",&sequent[i]);
    buildtree(1,1,n);
    int order;
    int x,y,k;
    for (int i = 0;i < m;i++){
        
    }
    return 0;
}