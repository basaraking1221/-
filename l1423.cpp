#include <iostream>
using namespace std;
int main(){
    double x;
    double step_length = 2;
    int steps = 0;
    cin>>x;
    while (x > 0){
        x -= step_length;
        step_length *= 0.98;
        steps++;
    }
    cout<<steps;
    return 0;
}