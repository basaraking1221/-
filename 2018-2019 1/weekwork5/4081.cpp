#include <iostream>
#include <algorithm>
using namespace std;
int mon[500010];
int max(int a,int b){
    if (a > b) return a;
    else return b;
}
int main(){
    int n,k;
    int head,tail;
    int temp,tempO,tempT;
    int left = 0;
    int all = 0;
    scanf("%d%d",&n,&k);
    for (int i = 0;i < n;i++)
        {scanf("%d",&mon[i]);all += mon[i];}
    sort(mon,mon + n);
    head = 0;tail = n - 1;
    temp = k;
    while (temp > 0 && head < n)
        if (temp >= (mon[head + 1] - mon[head]) * (head + 1)){
             temp -=(mon[head + 1] - mon[head]) * (head + 1);
             head++;
        }
        else break;
    while (k > 0 && tail >= 0)
        if (k >= (mon[tail] - mon[tail - 1]) * (n - tail)){
            k -= (mon[tail] - mon[tail - 1]) * (n - tail);
            tail--;
        }
        else break;
    tempO = mon[head];tempT = mon[tail];
    if (tempO >= tempT)
        if (all % n == 0) tempO = tempT;
        else tempT = tempO + 1;
    else{
        tempO += temp / (head + 1);
        tempT -= k / (n - tail);
        if (tempO >= tempT)
            if (all % n == 0) tempO = tempT;
            else tempT = tempO + 1;
    }
    printf("%d",tempT - tempO);
    return 0;
}