#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn=10010;
const int INF=1<<30;
int price[maxn],sell[maxn],d[maxn];
int n,p;
int num;
int main(){
    while(cin>>n){
        int k=0;
        while(true){
            int x,y;
            cin>>x>>y;
            if(x == -1 && y == -1)break;
            k++;
            price[k] = x;
            sell[k] = y;
        }
        cin>>num;

        int p=price[1];
        int most=price[k]+sell[k]/num;
        if((n < p) || (n > most)){
            cout<<"NO SOLUtION"<<endl;
            continue;
        }
        memset(d,0,sizeof(d));
        for(int i = 1;i <= k - 1;i++){
            int tt = (sell[i] - sell[i+1]) / (price[i+1] - price[i]);
            for(int j = price[i];j <= price[i+1] - 1;j++)
                d[j] = sell[i] - tt*(j - price[i]);
        }
        for(int i = price[k];i <= most;i++)
            d[i] = sell[k] - num * (i - price[k]);
        double k1 = -INF,k2 = INF;
        for(int i = p;i <= most;i++){
            int r = d[n] - d[i];
            int ans = i * d[i] - n * d[n] - p * (d[i] - d[n]);
            if(r > 0 && k1 < (double)ans / (double)r)
                k1 = (double)ans / (double)r;
            if(r < 0 && k2 > (double)ans / (double)r)
                k2 = (double)ans / (double)r;
        }
        int u1,u2;
        if (k1 == -INF) u1 = -INF;
        else if (k1 > 0 && (k1 - (int)k1 > 0)) u1 = (int)k1 + 1;
        else u1 = k1;
        if (k2 == INF)   u2 = INF;
        else if(k2 < 0 && ((int)k2 - k2 > 0))  u2 = (int)k2 - 1;
        else u2 = k2;
        if(u1 < 0 && u2 > 0){
            u1 = 0;
            u2 = 0;
        }
        if (u1 > u2)  cout<<"NO SOLUTION"<<endl;
        else if(abs(u1) < abs(u2))  cout<<u1<<endl;
        else cout<<u2<<endl;
    }
    return 0;
}