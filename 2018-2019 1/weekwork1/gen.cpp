#include <iostream>
#include <random>
#include <windows.h>
using namespace std;
int main()
{
    srand(GetTickCount());
    int y1 = rand() % 200 + 1850;
    int y2 = y1 + rand() % 200 + 1;
    if (y2>2050) y2 = 2050;
    int a = rand() % 12 + 1;
    int b = rand() % 7 + 1;
    int c = rand() %6 + 1;
    printf("%d %d %d %d %d",a,b,c,y1,y2);
    return 0;
}