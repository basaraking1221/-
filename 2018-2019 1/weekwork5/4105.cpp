#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int m,n;
int temp;
int a[200010];
void doit(int num,int left,int right)
{
    if (right - left == 1)
        printf("%d\n", min( abs(a[left] - num) , abs(a[right] - num) ) );
    else
    {
        int mid = (left + right) / 2;
        if (a[mid] < num) doit(num, mid, right);
        else doit(num, left , mid);
    }
}
int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 0;i < n;i++) scanf("%d",&a[i]);
    sort(a,a + n);
    for (int i = 0;i < m;i++)
    {
        scanf("%d",&temp);
        doit(temp,0,n - 1);
    }
    return 0;
}