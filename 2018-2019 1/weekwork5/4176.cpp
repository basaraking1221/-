#include <iostream>
using namespace std;
struct point{
    int value;
    int pnum;
    point *next;
};
void insert(point *now,int numo,int numt)
{
    point *tempt;
    now->value++;
    tempt = now->next;
    now->next = new point;
    now->next->next = tempt;
    tempt = now->next;
    tempt->pnum = numo;
    tempt->value = numt;
}
void cleard(point *now)
{
    if (now->next != NULL)
        cleard(now->next);
    delete now;
}
point station[1010];
point *tem;
int te,tet;
int n,a,b;

struct loc
{
    int num;int value;
    loc(){}
    loc(int n,int v):num(n),value(v){}
};
int ans[1010];
bool outp[1010] = {0};

loc po[3002];//这是一个1-base的堆
loc temp;
int ponum = 0;
bool ger(const loc &a,const loc &b){
    if (a.value > b.value) return true;
    return false;
}
void exchange(loc &a,loc &b){
    temp = a;
    a = b;
    b = temp;
}
void justifyB(int n){
    if (n <= 1) return;
    if (n % 2 == 0)
        if (ger(po[n],po[n / 2])) return;
        else
        {
            exchange(po[n],po[n / 2]);
            justifyB(n / 2);
        }
    else if (ger( po[n],po[(n - 1) / 2] )) return;
        else
        {
            exchange(po[n],po[(n - 1) / 2]);
            justifyB((n - 1) / 2);
        }
}//自底向上调整
void justifyT(int n){
    if (n * 2 > ponum) return;
    if (ger(po[n * 2], po[n]) && ger(po[n * 2 + 1],po[n])) return;
    if ( ger(po[n * 2],po[n * 2 + 1]) )
    {
        exchange(po[n], po[n * 2 + 1]);
        justifyT(n * 2 + 1);
        return;
    }
    else
    {
        exchange(po[n],po[n * 2]);
        justifyT(n * 2);
        return;
    }
}//自顶向下调整
void insert(const loc &in){
    ponum++;
    po[ponum] = in;
    justifyB(ponum);
}
void del(int n){
    po[n] = po[ponum];
    ponum--;
    justifyT(n);
}
loc poptop(){
    loc tem = po[1];
    del(1);
    return tem;
}
int main()
{
    scanf("%d%d%d",&n,&a,&b);
    for (int i = 1;i <= n;i++)
    {
        scanf("%d",&te);
        if (te == 0) continue;
        scanf("%d",&tet);
        insert(&station[i],tet,0);
        for (int j = 1;j < te;j++)
        {
            scanf("%d",&tet);
            insert(&station[i],tet,1);
        }
        ans[i] = 1000000000;
    }

    ans[a] = 0;
    po[1].num = a;
    po[1].value = 0;ponum = 1;
    while (ponum > 0)
    {
        temp = poptop();
        tet = temp.num;
        tem = &station[tet];
        for (int i = 0;i < station[tet].value;i++)
        {
            tem = tem->next;
            if (ans[tem->pnum] > ans[tet] + tem->value)
            {
                ans[tem->pnum] = ans[tet] + tem->value;
                insert(loc(tem->pnum,ans[tem->pnum]));
            }
        }
    }

    for (int i = 1;i <= n;i++)
    if (station[i].next != NULL)
        cleard(station[i].next);
    if (ans[b] == 1000000000) printf("-1");
    else printf("%d",ans[b]);
    return 0;
}