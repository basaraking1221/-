#include<cstdio>
#include<algorithm>
using namespace std;
void doit(long long i, long long j);
long long n;
int main()
{
    long long i,j,k;
    scanf("%lld%lld%lld",&n,&i,&j);
    doit (j, n + 1 - i);
    doit (n + 1 - j, i);
    return 0;
}
void doit(long long i, long long j)
{
    long long x, ans;
    x=min(i - 1, n - i);
    x=min(x, j - 1);
    x=min(x, n - j);
    ans=4 * n * x - 4 * x * x;

    if (i - x == 1)  ans += j - x;
    else if(i + x == n)  ans += 3 * n - 5 * x - 1 - j;
    else if(j - x == 1)  ans += 4 * n - 7 * x - 2 - i;
    else ans += n - 3 * x + i - 1;
    printf("%lld ",ans - 1);    
}