#include <iostream>
using namespace std;
int main()
{
    long long n;
    int x;
    scanf("%d%lld", &x, &n);
    long long weeks = n / 7;
    int left =  n % 7;
    long long ans = weeks * 1250;
    for (int i = 1;i <= left;i++)
    {
        if (x++ <= 5) ans += 250;
        if (x > 7) x -= 7;
    }
    printf("%lld", ans);
    return 0;
}