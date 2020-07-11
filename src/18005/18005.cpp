#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long int N;
    cin >> N;
    if(N%4==0) cout << 2;
    else if(N%2==0) cout << 1;
    else cout << 0;
}