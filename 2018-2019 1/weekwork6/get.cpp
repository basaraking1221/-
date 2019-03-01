#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
const int conb = 1e3;
const int con = 100;
int main(){
    srand(GetTickCount());
    int f,tt;
    int a[3],t[3],p[3];
    do{
        f = rand() % conb; tt = rand() % 10000;
        t[0] = rand() % con;t[1] = rand() % con; t[2] = rand() % con;
        a[1] = rand() % con + 1;a[2] = rand() % con + 1; p[1] = rand() % con; p[2] = rand() % con;
    } while (f / a[1] * t[1] > tt && f / a[2] * t[2] > tt);
    printf("%d %d %d\n",f,tt,t[0]);
    for (int i = 1;i <= 2;i++)
        printf("%d %d %d\n",a[i],t[i],p[i]);
    return 0;
}