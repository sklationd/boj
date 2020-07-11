#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N,M;
    cin >> N >> M;
    if(N==M) cout << 1;
    else cout << 0;
}