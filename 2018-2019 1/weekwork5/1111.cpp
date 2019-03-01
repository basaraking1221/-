#include <iostream>
#include <cstring>
using namespace std;
struct bitree
{
    int left,right;
    char value;
    int num;
};
int pos = -1,tnum = 0;
int l;
char fo[30],mi[30];
bitree t[1010];
char ans[1010];
void doit(int left,int right,int now)
{
    pos++;
    if (left == right)
    {
        t[now].value = fo[pos];
        return;
    }
    int ans;
    for (int i = left;i <= right;i++)
    if (fo[pos] == mi[i])
    {
        ans = i;
        break;
    }
    t[now].value = fo[pos];
    if (ans > left)
    {
        t[now].left = ++tnum;
        doit(left,ans - 1,tnum);
    }
    if (ans < right)
    {
        t[now].right = ++tnum;
        doit(ans + 1,right,tnum);
    }
}
void checkIt(int now)
{
    if (t[now].left != 0)
        if (t[t[now].left].value != 0)
        {
            t[t[now].left].num = t[now].num * 2;
            ans[t[now].num * 2] = t[t[now].left].value;
            checkIt(t[now].left);
        }
        else;
    else;
    if (t[now].right != 0)
        if (t[t[now].right].value != 0)
        {
            t[t[now].right].num = t[now].num * 2 + 1;
            ans[t[now].num * 2 + 1] = t[t[now].right].value;
            checkIt(t[now].right);
        }
        else;
    else;
}

int main()
{
    cin>>fo;
    cin>>mi;
    l = strlen(fo);
    doit(0,l - 1,0);
    int ansn = 0;
    memset(ans,0,sizeof(ans));
    ans[1] = t[0].value;
    t[0].num = 1;
    checkIt(0);
    for (int i = 1009;i >= 1;i--)
        if (ans[i] != 0)
        {
            ansn = i;
            break;
        }
    for (int i = 1;i <= ansn;i++)
        if (ans[i] == 0) printf("NULL ");
        else printf("%c ",ans[i]);
    return 0;
}