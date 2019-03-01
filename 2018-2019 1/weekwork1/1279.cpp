#include <iostream>
#include <cstring>
using namespace std;
int translate(char* inp);
void outp(int numb, int tim);
int main()
{
    int n;
    int rep=0;
    static int tel[100001];
    scanf("%d", &n);
    
    for (int i = 1;i <= n;i++)
    {
        char inp[100];
        scanf("%s", inp);
        tel[i] = translate(inp);
    }

    bool hasone=0;
    static int rept[10000000];
    memset(rept, 0, sizeof(rept));
    for (int i = 1;i <= n;i++)
        rept[tel[i]]++;
    
    for (int i = 0;i <= 9999999;i++)
        if (rept[i] > 1)
            {
                hasone=1;
                printf("%03d-%04d %d\n", i/10000, i%10000, rept[i]);
            }
    if (!hasone) printf("No duplicates.");
    return 0;
}
int translate(char* inp)
{
    int len = strlen(inp);
    int re=0;
    for (int i = 0;i < len;i++)
        switch (inp[i])
        {
            case 'A' : case 'B' : case 'C' : case '2' : 
                re = re *10 + 2;
                break;
            case 'D' : case 'E' : case 'F' : case '3' : 
                re = re *10 + 3;
                break;
            case 'G' : case 'H' : case 'I' : case '4' : 
                re = re *10 + 4;
                break;
            case 'J' : case 'K' : case 'L' : case '5' : 
                re = re *10 + 5;
                break;
            case 'M' : case 'N' : case 'O' : case '6' : 
                re = re *10 + 6;
                break;
            case 'P' : case 'R' : case 'S' : case '7' : 
                re = re *10 + 7;
                break;
            case 'T' : case 'U' : case 'V' : case '8' : 
                re = re *10 + 8;
                break;
            case 'W' : case 'X' : case 'Y' : case '9' : 
                re = re *10 + 9;
                break;
            case '1' : 
                re = re * 10 + 1;
                break;
            case '0':
                re = re *10;
                break;
            default: break;
        }
    return re;
}