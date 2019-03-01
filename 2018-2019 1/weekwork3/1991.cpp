#include <iostream>
#include <cmath>
using namespace std;
int check(double r);
int k,n;
double x[100001];
int main()
{
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= n;i++)
        scanf("%lf", &x[i]);

    double r = (abs(x[1] - x[n])) / 2;
    double l = 0;
    for (int i = 0;i < 100;i++)
    {
        double mid = (r + l) / 2;
        if (check(mid))
        r = mid;
        else l = mid;
    }
    printf("%.6f", l);
    return 0;
}
const double eps = 1e-8;
int dcmp (double x)
{
    return (x > eps) - (x < -eps);
}
int check(double r)
{
    int left = k - 1;
    double d = x[1] + 2 * r;
    for (int i = 2;i <= n;i++)
        if (dcmp(d - x[i]) >= 0) continue;
        else if (left > 0)
        {
            left--;
            d = x[i] + 2 * r;
        }
        else
        return 0;
    return 1;
}