#include <iostream>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    int a0 = 0;
    int a1 = 1;
    int t;
    for(i=0;i<N-1;i++){
        t = a1;
        a1 = a1+a0;
        a0 = t;
    }
    cout << a1;
}