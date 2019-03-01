#include <iostream>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;
int main()
{
    srand(GetTickCount());
    int n = rand() % 100 + 1;
    int k = rand() % n + 1;
    printf("%d %d\n", n, k);
    double a[100001];
    for (int i = 0;i < n; i++)
        a[i] = (rand() * 10000) / 10000000.0 - (rand() * 100000) / 10000000.0;
    sort(a,a+n);
    for (int i = 0;i < n;i++) printf("%.6lf ", a[i]);
    return 0;
}