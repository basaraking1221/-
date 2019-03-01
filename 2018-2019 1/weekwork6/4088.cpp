#include <bits/stdc++.h>
using namespace std;
template <class T>
T divv(T a,T b){
    return a / b + !!(a % b);
}
int main(){
    long long f,tt;
    long long a[3],t[3],p[3];
    long long ans = -1;
    long long maxn,nn;long long temp;
    scanf("%lld%lld%lld",&f,&tt,&t[0]);
    for (int i = 1;i <= 2;i++)
        scanf("%lld%lld%lld",&a[i],&t[i],&p[i]);
    maxn = divv (f,a[1]);
    for (long long n = 0;n <= maxn;n++){
        if (tt < t[1] * n * a[1]) break;
        if (f - n * a[1] > 0){
            if (t[0] <= t[2]){
                if ((f - n * a[1]) * t[0] + n * t[1] * a[1]<= tt){
                    ans = n * p[1];break;
                }
            }
            
            else{

                if ( divv( f - a[1] * n,a[2]) * a[2] * t[2] <= (tt - a[1] * n * t[1]) ) {
                    if ((ans == -1) || (ans > n * p[1] +divv((f - a[1] * n),a[2]) * p[2]))
                    ans = n * p[1] +divv((f - a[1] * n),a[2]) * p[2];
                    temp = 1;
                }

                if ( (f - a[1] * n) / a[2] * a[2] * t[2] + (f - a[1] * n) % a[2] * t[0]
                <= (tt - a[1] * n * t[1]) )
                {
                    temp = (f - a[1] * n) * t[0] + a[1] * t[1] * n - tt;
                    if (temp < 0) temp = 0;
                    nn = divv(temp, a[2] * (t[0] - t[2]));
                    if ((ans > nn * p[2] + n * p[1])||(ans == -1)) ans = nn * p[2] + n * p[1]; 
                }
                
            }

        }    
        else if ((ans > n * p[1])||(ans == -1)) ans = n * p[1];
    }
    printf("%lld",ans);
    return 0;
}