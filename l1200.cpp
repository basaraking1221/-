#include <iostream>
#include <string>
using namespace std;
int main(){
    string g,u;
    cin>>g>>u;
    int gr = 1,uf = 1;
    for (int i = 0;i < g.length();i++)
        gr = gr * (g[i] - 'A' + 1) % 47;
    for (int i = 0;i < u.length();i++)
        uf = uf * (u[i] - 'A' + 1) % 47;
    if (gr == uf) cout<<"GO";
    else cout<<"STAY";
    return 0;
}