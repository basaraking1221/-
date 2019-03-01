#include <stdio.h>
#include <algorithm>
using namespace std;
struct inf{
    int value;
    int num;
}person[20005];
bool operator<(inf a,inf b){
    if (a.value != b.value) return a.value > b.value;
    else return a.num <b.num;
}
int main(){
    int e[11];
    int n,k;
    scanf("%d%d",&n,&k);
    for (int i = 1;i <= 10;i++) scanf("%d",&e[i]);
    for (int i = 1;i <= n;i++){
        scanf("%d",&person[i].value);
        person[i].num = i;
    }
    sort(person + 1,person + n + 1);
    for (int i = 1;i <= n;i++)
        person[i].value += e[(i - 1) % 10 + 1];
    sort(person + 1,person + n + 1);
    for (int i = 1;i <= k;i++) printf("%d ",person[i].num);
    return 0;
}