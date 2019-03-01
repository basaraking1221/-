#include <iostream>
using namespace std;
int main()
{
    int n,l;
    scanf("%d%d", &n, &l);
    int location;
    int max=0;
    int min=1000000001;
    for (int i = 0;i < n;i++)
    {
        scanf("%d", &location);
        int time;
        if (i%2 == 0) time = l - location;
            else time = location;
        if (max < time) max = time;
        if (min > time) min = time;
    }
    printf("%d %d", min, max);
    return 0;
}