#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double A,B,C;
    cin >> A >> B >> C;
    if (B<=C) cout << (long long int)((A/B)*C);
    else cout << (long long int)((A*B)/C);
}