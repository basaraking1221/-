#include <iostream>
using namespace std;
int main()
{
    int twoh,chairh,num;
    
    scanf("%d%d%d",&twoh,&chairh,&num);
    int ans=0;
    int inp;
    twoh+=chairh;
    for (int i=0;i<num;i++)
    {
        scanf("%d",&inp);
        if (inp<=twoh) ans++;
    }

    printf("%d",ans);
    return 0;
}