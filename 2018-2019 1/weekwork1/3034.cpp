#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    static bool chosen[1001001];
    static int table[1001000];
    int num=1;
    int n;

    memset(chosen, 0, sizeof(chosen));
    table[1]=2;
    chosen[4]=1;
    for (int i = 3;i < 1001000;i++)
    {
        for (int j = 1;j <= num; j++)
            {
                if (i * table[j] >  1001000) break;
                chosen[i * table[j]]=1;
                if (i%table[j] == 0)
                {
                    chosen[i] = 1;
                    break;
                }
            }
        if (!chosen[i]) table[++num] = i;
    }

    scanf("%d",&n);
    for (int i=1;i<num;i++)
        if (table[i]==n)
        {
            printf("%d", 0);
            break;
        }
        else if ((table[i] < n)&&(table[i + 1] > n))
            {
                printf("%d", table[i+1]-table[i]);
                break;
            }
    return 0;
}