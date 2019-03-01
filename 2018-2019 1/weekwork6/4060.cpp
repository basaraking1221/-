#include <iostream>
using namespace std;
long long min(long long a,long long b){
    if (a > b) return b;
    else return a;
}
int main(){
    int n;
    long long t[105] = {0};
    scanf("%d",&n);
    for (int i = 0;i < n;i++) scanf("%lld",&t[i]);
    long long ans[105][2] = {0};
    ans[0][0] = ans[0][1] = t[0];
    ans[1][0] = ans[1][1] = t[1];
    ans[2][0] = ans[2][1] = t[0] + t[1] + t[2];
    for (int i = 3;i < n;i++){
        ans[i][0] = min(ans[i - 1][0],ans[i - 1][1]) + t[i] + t[0];
        ans[i][1] = min(ans[i - 2][0],ans[i - 2][1]) + t[i] + 2 * t[1] + t[0];
    }
    printf("%lld",min(ans[n - 1][0],ans[n - 1][1]));
    return 0;
}