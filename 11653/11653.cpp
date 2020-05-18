#include <iostream>
#include <cmath>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    while(N%2==0){
        cout << 2 << endl;
        N/=2;
    }
    for(i=3;i<=sqrt(N);i+=2){
        while(N%i==0){
            cout << i << endl;
            N/=i;
        }
    }
    if (N > 2)
        cout << N;
}