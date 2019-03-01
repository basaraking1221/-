#include <iostream>
using namespace std;
bool judge(int a,int b,int c);
int main(){
    for (int i = 123;i <= 329;i++){
        if (judge(i,2 * i,3 * i))
            printf("%d %d %d\n",i,2 * i,3 * i);
    }
    return 0;
}
bool judge(int a,int b,int c){
    bool choosen[10] = {0};
    int temp[3] = {a,b,c};
    int now;
    for(int i = 0;i < 3;i++)
        for(int j = 0;j < 3;j++) {
        now = temp[j] % 10;
        if (now != 0)
            if (choosen[now]) return false;
            else choosen[now] = true;
        else return false;
        temp[j] /= 10;
    }
    return true;
}