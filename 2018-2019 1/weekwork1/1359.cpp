#include <iostream>
using namespace std;
int main()
{
    char c;
    int ans=0;
    int num=1;
    while ((c=getchar())!='\n')
    {
        if ((c>='A')&&(c<='Z')) ans+=(c+1-'A')*num;
        if ((c>='a')&&(c<='z')) ans+=(c+1-'a'+26)*num;
        num++;
    }
    printf("%d",ans);
    return 0;
}