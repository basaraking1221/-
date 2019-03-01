#include <iostream>
using namespace std;
const int modd = 1000000007;
struct tMatrix{
    long long a,b,c,d;
};
tMatrix ans,temp;
tMatrix mul(const tMatrix &a,const tMatrix &b){
    tMatrix tt;
    tt.a = ((a.a * b.a) % modd + (a.b * b.c) % modd) % modd;
    tt.b = ((a.a * b.b) % modd + (a.b * b.d) % modd) % modd;
    tt.c = ((a.c * b.a) % modd + (a.d * b.c) % modd) % modd;
    tt.d = ((a.c * b.b) % modd + (a.d * b.d) % modd) % modd;
    return tt;
}
void doit (long long n){
    if (n <= 1) return;
    if (n % 2 != 0){
        temp = mul(ans,temp);
    }
    ans = mul(ans,ans);
    doit(n / 2);
    return;
}
int main(){
    long long n;
    scanf("%lld",&n);
    ans.a = ans.b = ans.c = 1;ans.d = 0;
    temp.a = temp.d = 1;temp.b = temp.d = 0;
    doit(n);
    ans = mul(ans,temp);
    int outp = (ans.a + ans.b) % modd;
    printf("%lld",outp);
    return 0;
}