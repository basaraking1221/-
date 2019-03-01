#include <iostream>
using namespace std;
int main()
{
    long long x,y,value;
    int n;
    char temp;
    int past = 0;
    long long times = 0;

    scanf("%d%lld%lld", &n, &x, &y);
    getchar();
    for (int i = 1;i <= n;i++)
    {
        scanf("%c", &temp);
        if (temp == '1') past = 0;
        else if (past) continue;
        else
        {
            past = 1;
            times++;
        }
    }
    if (times == 0)
    {
        printf("0");
        return 0;
    }
    value = y;
    if (x > y) value += y * (times - 1);
    else value += x * (times - 1);
    printf("%lld", value);
    return 0;
}