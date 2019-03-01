#include <iostream>
using namespace std;
int main()
{
    int best,nowin;
    best=0;
    for (int i=0;i<3;i++)
    {
        scanf("%d",&nowin);
        if (nowin>best) best=nowin;
    }
    printf("%d",best);
    cin>>best;
    return 0;
}