#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int cir(char* s);
void adds(char* s);

int n;

int main()
{
    char num[200]={0};
    int step = 0;

    scanf("%d", &n);
    scanf("%s", num);
    int l = strlen(num);
    reverse(num,num+l);
    do
    {
        if (cir(num)) break;
        if (step == 30)
        {
            step++;
            break;
        }
        adds(num);
        step++;
    }
    while (step <= 30);
    if (step > 30) printf("Impossible!");
    else printf("STEP=%d", step);
    return 0;
}

int cir(char* s)
{
    int l = strlen(s);
    if (l == 1) return 1;
    for (int i = 0;i <= l/2 - 1;i++)
        if (s[i] != s[l-1-i]) return 0;
    return 1;
}
void adds(char* s)
{
    int l = strlen(s);
    int temp[200] = {0};
    for (int i = 0;i < l;i++)
        {
            if ((s[i]<='9')&&(s[i]>='0')) temp[i] = s[i] - '0';
            else temp[i] = s[i] - 'A' + 10;
            if ((s[l-1-i]<='9')&&(s[l-1-i]>='0')) temp[i] += s[l-1-i] - '0';
            else temp[i] += s[l-1-i] - 'A' + 10;
        }
    for (int i = 0;i < l;i++)
        if (temp[i]>=n)
        {
            temp[i + 1] += temp[i]/n;
            temp[i] %= n;
        }
    for (int i = 0;i < l;i++)
        if (temp[i]<=9) s[i] = temp[i] + '0';
        else s[i] = temp[i] - 10 + 'A';
    if (temp[l] != 0)
        if (temp[l]<=9) s[l] = temp[l] + '0';
        else s[l] = temp[l] - 10 + 'A';
}