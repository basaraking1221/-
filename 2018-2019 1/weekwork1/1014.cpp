#include <iostream>
#include <cstring>
using namespace std;
void chplus(char* a, char* b, char* c, int la, int lb);
int main()
{
    char a[100001],b[100001];
    scanf("%s", a);
    scanf("%s", b);
    int a_len, b_len;
    a_len = strlen(a);
    b_len = strlen(b);
    char temp;
    for (int i = 0;i < a_len/2;i++)
    {temp = a[i]; a[i] = a[a_len-1-i]; a[a_len-1-i] = temp;}
    for (int i = 0;i < b_len/2;i++)
    {temp = b[i]; b[i] = b[b_len-1-i]; b[b_len-1-i] = temp;}

    char c[100002] = {0};    
    if (a_len >= b_len) chplus(a, b, c, a_len, b_len);
        else chplus(b, a, c, b_len, a_len);

    int c_len = strlen(c);
    for (int i = 0;i < c_len/2;i++)
    {temp = c[i]; c[i] = c[c_len-1-i]; c[c_len-1-i] = temp;}    
    printf("%s", c);
    return 0;
}

void chplus(char* a, char* b, char*c, int la, int lb) //always, la>=lb
{
    short add = 0;
    for (int i = 0;i < lb;i++)
    {
        c[i] = a[i] + b[i] + add - '0';
        if (c[i] > '9')
        {
            c[i] -= 10;
            add = 1;
        }
        else add = 0;
    }
    for (int i = lb;i < la;i++)
    {
        c[i] = a[i] + add;
        if (c[i] >'9')
        {
            c[i] -= 10;
            add = 1;
        }
        else add = 0;
    }
    if (add == 1) c[la]='1';
    return;
}