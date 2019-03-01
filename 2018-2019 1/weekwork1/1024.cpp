#include <iostream>
using namespace std;

int num[10000];
int cop[10000] = {0};

void sor(int l,int r);

int main()
{
    int n;

    scanf("%d", &n);
    for (int i = 1;i <= n;i++)
        scanf("%d", &num[i]);
    sor(1,n);
    for (int i = 1;i <= n;i++)
        printf("%d ", num[i]);
    return 0;
}

void sor(int l,int r)
{
    if (l==r) return;
    sor(l, (l + r) / 2);
    sor((l + r) / 2 + 1, r);
    int head_l=l;
    int head_r=(l + r) / 2 + 1;
    for (int i = l;i <= r;i++)
        if ((head_l <= (l + r) / 2) && (head_r <= r))
            if (num[head_l] < num[head_r])
                cop[i] = num[head_l++];
            else cop[i] = num[head_r++];
        else if (head_l > (l + r) / 2)
            cop[i] = num[head_r++];
            else cop[i] = num[head_l++];
    for (int i = l;i <= r;i++)
        num[i] = cop[i];
    return;
}