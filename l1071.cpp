#include <stdio.h>
#include <cstring>
int main(){
    char inf[3][105];
    for (int i = 0;i < 3;i++) scanf("%s",inf[i]);
    char cha[30],ori[30];
    for (int i = 0;i < 26;i++) cha[i] = ori[i] = 0;
    for (int i = 0;i < strlen(inf[0]);i++)
        if (!cha[inf[0][i] - 'A'] && !ori[inf[1][i] - 'A']){
            cha[inf[0][i] - 'A'] = inf[1][i];
            ori[inf[1][i] - 'A'] = inf[0][i];
        }
        else if (cha[inf[0][i] - 'A'] != inf[1][i] || ori[inf[1][i] - 'A'] != inf[0][i]){
            printf("Failed");
            return 0;
        }
    for (int i = 0;i < 26;i++)
        if (!cha[i] || !ori[i]){
            printf("Failed");
            return 0;
        }
    for (int i = 0;i < strlen(inf[2]);i++)
        printf("%c",cha[inf[2][i] - 'A']);
    return 0;
}