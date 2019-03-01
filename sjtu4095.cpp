#include <stdio.h>
int n,m;
int tree[400005];
void buildtree(int a,int l,int r){
    if (l == r){
        tree[a] = 1;
        return;
    }
    buildtree(2 * a,l,(l + r) / 2);
    buildtree(2 * a + 1,(l + r) / 2 + 1,r);
    tree[a] = tree[2 * a] + tree[1 + 2 * a];
}
/*int sum(int a,int b,int l,int r,int p){
    if (a == l && b == r){
        return tree[p];
    }
    int mid = (a + b) / 2;
    if (mid >= r) return sum(a,mid,l,r,2 * p);
    if (mid < l) return sum(mid + 1,b,l,r,2 * p + 1);
    return sum(a,mid,l,mid,2 * p) + sum(mid + 1,b,mid + 1,r,2 * p + 1);
}
/*void increase(int a,int b,int p,int f,int s){   //now for [a,b],tree[p],find f and add s on it
    if (a == b && a == f) tree[p] += s;
    int mid = (a + b) / 2;
    if (mid >= f){
        change(a,mid,2 * p,f,s);
        tree[p] += s;
    }
    else{
        change(mid + 1, b, 2 * p,f,s);
        tree[p] += s;
    }
}*/
void find_and_decrease(int a,int b,int p,int f){
    if (a == b){
        tree[p]--;
        return;
    }
    int mid = (a + b) / 2;
    if (tree[2 * p] < f){
        f -= tree[2 * p];
        find_and_decrease(mid + 1,b,2 * p + 1, f);
    }
    else find_and_decrease(a,mid,2 * p,f);
    tree[p]--;
}
int main(){
    scanf("%d%d",&n,&m);
    buildtree(1,1,n);
    int now = n;
    int k;
    int po = 1,lr = 0;          //lr: 0 for right and 1 for left
    while(now > 1){
        k = (m - 1) % (2 * now - 2);
        if (lr){
            if (k < po - 1) po -= k;
            else if (k < now + po - 2){
                lr = 0;
                po = 2 + k - po;
            }
            else po = 2 * now + po - 2 - k;
        }
        else{
            if (k < now - po) po += k;
            else if (k < 2 * now - po - 1){
                lr = 1;
                po = 2 * now - po - k;
            }
            else po = k + po + 2 - 2 * now; 
        }
        find_and_decrease(1,n,1,po);
        if (lr) po--;
        now--;
    }
    int l = 1,r = n,p = 1;
    while(l != r){
        if (tree[2 * p]){
            p *= 2;
            r = (l + r) / 2;
        }
        else{
            p = p * 2 + 1;
            l = (l + r) / 2 + 1;
        }
    }
    printf("%d",l);
    return 0;
}