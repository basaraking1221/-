#include <iostream>
using namespace std;
struct point{
    int father,value,sonNum;
    int head;
};
point t[10005];
int nex[10005];
void doit(int num)
{
    int temp;
    temp = t[num].head;
    while(temp != 0){
        doit(temp);
        t[num].sonNum += t[temp].sonNum + 1;
        temp = nex[temp];
    }
}
int main(){
    int n;
    int anc;
    int temp;
    scanf("%d",&n);
    for (int i = 1;i <=n;i++){
        scanf("%d%d",&t[i].father,&t[i].value);
        if (t[i].father == 0) anc = i;
        else {
            if (t[t[i].father].head != 0){
                temp = t[t[i].father].head;
                nex[i] = temp;
                t[t[i].father].head = i;
            }
            else t[t[i].father].head = i;
        }
    }
    doit(anc);
    long long ans = 0;
    for (int i = 1;i <= n;i++){
        if (t[i].father != 0)
            ans += 1LL * (t[i].sonNum + 1) * (n - t[i].sonNum - 1) * t[i].value;
    }
    double a = ans / (double) n;
    a /= n - 1.0;
    a *= 2.0;
    printf("%.2f",a);
    return 0;
}