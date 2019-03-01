#include <iostream>
#include <cstring>
using namespace std;
char t[1000005];
char c[1000005];
int n;
int nn;
void inF(int num){
    t[num] = c[nn++];
    if (num * 2 <= n) inF(num * 2);
    if (num * 2 + 1 <= n) inF(num * 2 + 1);
}
void inM(int num){
    if (num * 2 <= n) inM(num * 2);
    t[num] = c[nn++];
    if (num * 2 + 1 <= n) inM(num * 2 + 1);
}
void inB(int num){
    if (num * 2 <= n) inB(num * 2);
    if (num * 2 + 1 <= n) inB(num * 2 + 1);
    t[num] = c[nn++];
}
void inC(){
    for (int i = 1;i <= n;i++) t[i] = c[nn++];
}
void outF(int num){
    printf("%c",t[num]);
    if (num * 2 <= n) outF(num * 2);
    if (num * 2 + 1 <= n) outF(num * 2 + 1);
}
void outM(int num){
    if (num * 2 <= n) outM(num * 2);
    printf("%c",t[num]);
    if (num * 2 + 1 <= n) outM(num * 2 + 1);
}
void outB(int num){
    if (num * 2 <= n) outB(num * 2);
    if (num * 2 + 1 <= n) outB(num * 2 + 1);
    printf("%c",t[num]);
}
void outC(){
    for (int i = 1;i <= n;i++) printf("%c",t[i]);
    printf("\n");
}


int main(){
    int tt;
    char ordero[100],ordert[100];
    scanf("%d",&tt);
    for (int i = 0;i < tt;i++){
        memset(t,0,sizeof(t));
        scanf("%d",&n);
        scanf("%s",ordero);scanf("%s",ordert);
        scanf("%s",c);
        nn = 0;
        if (ordert[0] == 'E'){
            inC();
            switch (ordero[1]){
                case 'N':outM(1);break;
                case 'R':outF(1);break;
                case 'O':outB(1);break;
                default:printf("WTF");return 0;
            }
            printf("\n");
        }
        else{
            switch (ordero[1]){
                case 'N':inM(1);break;
                case 'R':inF(1);break;
                case 'O':inB(1);break;
                default:printf("WTF");return 0;
            }
            outC();
        }
    }
    return 0;
}