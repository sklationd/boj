#include <iostream>

typedef long long int ll;

using namespace std;

ll power(ll A, ll B, ll C){
    if(B==0){
        return 1;
    }
    if(B==1){
        return A%C;
    }
    if(B%2){
        ll div = power(A,B/2,C)%C;
        return ((div*div)%C * A%C)%C; 
    } else {
        ll div = power(A,B/2,C)%C;
        return (div*div)%C;
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll A,B,C;
    cin >> A >> B >> C;
    ll r = power(A,B,C);
    cout << r;
}