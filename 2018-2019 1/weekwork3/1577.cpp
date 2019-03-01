#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    int ans = 0;
    char cor[101];
    char temp[1000];
    scanf("%d",&n);
    scanf("%s",temp);
    int lc = -1;
    for (int i = 0;i < strlen(temp);i++)
        if ( ('a' <= temp[i]) && ('z' >= temp[i]) ) cor[++lc] = temp[i];
    for (int i = 0;i < n;i++)
    {
        char now[101];
        scanf("%s",temp);
        int ln = - 1;
        for (int i = 0;i < strlen(temp);i++)
            if ( ('a' <= temp[i]) && ('z' >= temp[i]) ) now[++ln] = temp[i];
        if (ln != lc) continue;
        ln++;
        for (int i = 0;i < ln;i++)
            if (now[i] != cor[0]) continue;
            else
            {
                int judge = 1;
                for (int j = 1;j < ln;j++)
                    if (cor[j]!=now[(i + j)%ln])
                    {
                        judge = 0;break;
                    }
                if (judge) {ans++;break;}
                judge = 1;
                for (int j = 1;j < ln;j++)
                    if (cor[j]!=now[(2 * ln + i - j)%ln])
                    {
                        judge = 0;break;
                    }
                if (judge) {ans++;break;}
            }
    }
    printf("%d",ans);
    return 0;
}