#include <iostream>
using namespace std;
int main()
{
    int n;
    int a,b;
    int last = 2000000000;

    scanf("%d", &n);
    for (int i = 0;i < n;i++)
    {
        scanf("%d%d", &a, &b);
        if ((a > last)&&(b > last))
            {
                printf("NO");
                return 0;
            }
        if (a > last) {last = b; continue;}
        if (b > last) {last = a; continue;}
        if (a > b) last = a; else last = b;
    }
    printf("YES");
    return 0;
}