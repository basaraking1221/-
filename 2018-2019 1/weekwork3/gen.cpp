#include <iostream>
#include <random>
#include <windows.h>
#include <algorithm>
using namespace std;
int main()
{
    srand(GetTickCount());

    int m,n;
    m = rand() % 5 + 1;
    n = rand() % 5 + 1;
    cout << m <<" " <<n <<endl;

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n ;++j){
            cout << rand() % 20 + 1 << " ";
        }
        cout << endl;
    }

    for (int i = 0; i < m; ++i){
        for (int j = 0; j < n ;++j){
            cout << rand() % 2 << " ";
        }
        cout << endl;
    }


    return 0;
}