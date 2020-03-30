#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    if(N%2) cout << ((N+1)/2)*((N+3)/2);
    else cout << ((N/2)+1)*((N/2)+1);
}