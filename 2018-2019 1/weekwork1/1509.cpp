#include <iostream>
using namespace std;

int main()
{
    int a,b,c,y1,y2;
    scanf("%d%d%d%d%d", &a, &b, &c, &y1, &y2);
    if (c == 7) c = 0;
    short we[202][13];
    we[0][1]=2;
    const short days[13]={0, 31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    for (int i = 0;i < 201;i++)
        for (int j = 1;j < 13;j++)
        {
            if ((i==0)&&(j==1)) continue; 
            if (j == 1)
                {we[i][j] = (we[i-1][12] + 3) % 7; continue;}
            if (j != 3)
                {we[i][j] = (we[i][j-1] + days[j-1]) % 7; continue;}
            if (j == 3)
                if ( ( (i + 1850) % 4) != 0)
                    we[i][j] = we[i][j-1];
                else if ( ( (i + 1850) % 100) != 0)
                    we[i][j] = (we[i][j-1] + 1) % 7;
                else if ( ( (i + 1850) % 400) != 0)
                    we[i][j] = we[i][j-1];
                else we[i][j] = (we[i][j-1] + 1) % 7;
        }
    
    for (int i = y1;i <= (y2);i++)
        {
            int date = 1 + c - we[i-1850][a];
            int compare;
            if (date > 0) date += (b - 1) * 7;
                else date += b * 7;
            if (a != 2)
                compare = days[a];
                else
                    {
                        if ((i%4) != 0) compare = 28;
                        else if ((i%100) != 0) compare = 29;
                        else if ((i%400) != 0) compare = 28; 
                        else compare = 29;
                    }
            if (date <= compare) printf("%d/%02d/%02d\n", i, a, date);
            else printf("none\n");
        }
    return 0;
}