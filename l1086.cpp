#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
struct pl{
    int x, y, num;
    pl() = default;
    pl(int xx,int yy,int nn):x(xx),y(yy),num(nn){}
};
bool operator<(pl a,pl b){
    return a.num > b.num;
}
int dist(pl a,pl b){
    return abs(a.x - b.x) + abs(a.y - b.y);
}
int main(){
    int m,n,k;
    int num,pnum = 0;
    pl pla[402];
    cin>>m>>n>>k;
    for (int i = 1;i <= m;i++)
        for (int j = 1;j <= n;j++){
            cin>>num;
            if (num){
                pla[pnum] = pl(i,j,num);
                pnum++;
            }
        }
    sort(pla,pla + pnum);
    num = 0;
    int now = 0;
    if (2 * pla[0].x + 1 > k){
        cout<<'0';
        return 0;
    }
    num = pla[0].num;
    k -= pla[0].x + 1;
    while(k > 0){
        if (now == pnum) break;
        if (k >= dist(pla[now],pla[now + 1]) + pla[now + 1].x + 1){
            k -= dist(pla[now],pla[now + 1]) + 1;
            now++;
            num += pla[now].num;
        }
        else break;
    }
    cout<<num;
    return 0;
}