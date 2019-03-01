#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int len = 4;
const int leng = 9999;

void pred(char* ch, int* a);

int a[1000] = {0};int b[1000] ={0};
int main()
{
    char aa[1001] = {0},bb[1001] = {0};
    int c[1001] = {0};

    scanf("%s", aa);scanf("%s", bb);
    int la = strlen(aa);int lb = strlen(bb);
    reverse(aa,aa+la);reverse(bb,bb+lb);

    pred(aa,a);pred(bb,b);

    c[0] = a[0] + b[0] - 1;
    for (int i = 1;i <= a[0]; i++)
        for (int j = 1; j <= b[0]; j++)
            {
                c[i + j - 1] += a[i] * b[j];
                if (c[i + j - 1] > leng)
                {
                    c[i + j] += c[i + j - 1] / (leng + 1);
                    c[i + j - 1] %= (leng + 1);
                    if ((i+j) > c[0]) c[0] = i + j;
                }
            }
    while (c[c[0]] > leng)
    {
        c[c[0] + 1] = c[c[0]] / (leng + 1);
        c[c[0]] %= (leng + 1);
        c[0]++;
    }
    printf("%d",c[c[0]]);
    for (int i = c[0] - 1;i>= 1; i--)
    printf("%04d",c[i]);
    return 0;
}

void pred(char* ch, int* a)
{
    int l = strlen(ch);
    int ll = l/len;
    for (int i = 0;i < ll;i++)
    {
        reverse(ch + len * i, ch + len * i + len);
        for (int j = 0;j < len;j++)
            (a[i + 1] *= 10) += ch[len * i + j] - '0';
    }
    a[0] = ll;
    if (ll * len != l)
    {
        a[0]++;
        reverse(ch + ll * len , ch + l);
        for (int i = ll * len;i < l;i++)
            (a[ll + 1] *= 10) += ch[i] - '0';
    }
    return;
}