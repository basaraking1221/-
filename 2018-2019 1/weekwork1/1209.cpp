#include <iostream>
using namespace std;
int main()
{
    int n;
    int judge;
    int ans = 0;
    scanf("%d", &n);
    for (int i = 0;i<n;i++)
    {
        scanf("%d", &judge);
        ans += __builtin_popcount(judge);
    }
    printf("%d", ans);
    return 0;
}