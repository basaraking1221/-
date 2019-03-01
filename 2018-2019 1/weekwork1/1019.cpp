#include <iostream>
#include <cstring>
using namespace std;
void test(void);
int main()
{
    int n;
    scanf("%d\n",&n);
    for (int i = 1;i <= n;i++) test();
    return 0;
}
void test(void)
{
    int left = 0;int right = 0;
    char inp[100];
    int le;
    scanf("%s",inp);
    le=strlen(inp);
    for (int i=0;i<le;i++)
    {
        if (inp[i] == '(') left++;
            else right++;
        if (right>left)
        {
            printf("NO\n");
            return;
        }
    }
    if (left == right) printf("YES\n");
        else printf("NO\n");
    return;
}