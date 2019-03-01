#include <iostream>
using namespace std;
int main()
{
    int n;
    int a[101];
    scanf("%d",&n);
    int al = 0;
    for (int i = 0;i < n;i++) {scanf("%d",&a[i]);al+=a[i];}
    al /= n;
    int ans = 0;
    for (int i = 0;i < n;i++)
        if (a[i] != al)
        {
            ans++;
            a[i + 1] += a[i] - al;
            a[i] = al;
        }
    printf("%d",ans);
    return 0;
}