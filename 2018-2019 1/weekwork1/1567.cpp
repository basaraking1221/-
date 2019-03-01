#include <iostream>
using namespace std;
int main()
{
    char c;
    int n;
    int cha;

    cin>>c>>n;
    cha=(n+1)/2;
    for (int i=1;i<=cha;i++)
        {
            for (int j=1;j<=cha-i;j++) cout<<' ';
            for (int j=1;j<=2*i-1;j++) cout<<c;
            cout<<endl;
        }
    for (int i=1;i<cha;i++)
    {
        for (int j=1;j<=i;j++) cout<<' ';
        for (int j=1;j<=2*cha-1-2*i;j++) cout<<c;
        cout<<endl;
    }
    return 0;
}
