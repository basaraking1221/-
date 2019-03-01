#include <iostream>
#include <string>
using namespace std;
int nex[30];//next box bumber of box i;when no box next nex[i]=-1
int head[30];//TOP box number of location i;when no box there head[i]=-1
int pos[30];//the location of box i->deal with a = b situation
//ground<-next<-next<-next<-head(top)
int temp,tt;
void bac(int a){
    temp = head[pos[a]];
    while(temp != a){
        tt = nex[temp];
        nex[temp] = head[temp];
        head[temp] = temp;
        pos[temp] = temp;
        temp = head[pos[a]] = tt;
    }
}
int main(){
    int n;
    string order;
    int a,b;
    scanf("%d",&n);
    for (int i = 0;i < n;i++){
        pos[i] = head[i] = i;
        nex[i] = -1;
    }
    getline(cin,order);
    for(;;){
        getline(cin,order);
        if (order[0] == 'q') break;
        a = order[5] - '0';
        b = order[12] - '0';
        if ((a == b)||(pos[a] == pos[b])) continue;
        if (order[0] == 'm')
            if (order[8] == 'v'){
                bac(a);
                head[pos[a]] = nex[a];
                nex[a] = head[pos[b]];
                pos[a] = pos[b];
                head[pos[b]] = a;
            }
            else{
                bac(a);
                bac(b);
                head[pos[a]] = nex[a];
                nex[a] = head[pos[b]];
                head[pos[b]] = a;
                pos[a] = pos[b];
            }
        else{
            if (order[8] == 'n')
                bac(b);
            tt = temp = head[pos[a]];
            while (temp != a){
                pos[temp] = pos[b];
                temp = nex[temp];
            }
            head[pos[a]] = nex[a];
            pos[a] = pos[b];
            nex[a] = head[pos[b]];
            head[pos[b]] = tt;
        }
    }
    for (int i = 0;i < n;i++){
        printf("%d: ",i);
        if (head[i] == -1){
            printf("\n");
            continue;
        }
        int outq[30] = {0};
        tt = -1;
        temp = head[i];
        while(temp != -1){
            outq[++tt] = temp;
            temp = nex[temp];
        }
        for (int j = tt;j > 0;j--) printf("%d ",outq[j]);
        printf("%d\n",outq[0]);
    }
    return 0;
}