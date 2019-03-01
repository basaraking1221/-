#include <iostream>
using namespace std;
void doit()
{
    int a[9][9];
    for (int i = 0;i < 9;i++)
        for (int j = 0;j < 9;j++)
            scanf("%d",&a[i][j]);
    for (int i = 0;i < 9;i++)
    {
        int ch[10] = {0};
        for (int j = 0;j < 9;j++)
        if (ch[a[j][i]] == 1)
        {
            printf("Wrong\n");
            return;
        }
        else ch[a[j][i]] = 1;
    }
    for (int i = 0;i < 9;i++)
    {
        int ch[10] = {0};
        for (int j = 0;j < 9;j++)
        if (ch[a[i][j]] == 1)
        {
            printf("Wrong\n");
            return;
        }
        else ch[a[i][j]] = 1;
    }
    for (int i = 0;i<3;i++)
        for (int j = 0;j < 3;j++)
        {
            int ch[10] = {0};
            for (int k = 0;k < 3;k++)
                for (int l = 0;l < 3;l++)
                if (ch[a[3*i+k][3*j+l]]==1)
                {
                    printf("Wrong\n");
                    return;
                }
                else ch[a[3*i+k][3*j+l]] = 1;
    }
    printf("Right\n");
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    for (int i = 0;i < n;i++) doit();
    return 0;
}