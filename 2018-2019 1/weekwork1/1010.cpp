#include <iostream>
using namespace std;
int main()
{
    int useage[13];
    int left=0;
    int sav=0;
    for (int i=1;i<=12;i++) scanf("%d",&useage[i]);
    for (int i=1;i<=12;i++) 
    {
        left+=300;
        if (left<useage[i])
        {
            printf("-%d",i);
            return 0;
        }
        left-=useage[i];
        if (left>=100)
        {
            sav+=(left/100)*100;
            left%=100;
        }
    }
    left+=sav*6/5;
    printf("%d",left);
    return 0; 
}