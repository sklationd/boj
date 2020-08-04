#include <iostream>
using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
    ll r = a%b;
    while(r){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

ll lcm(ll a, ll b){
    ll d = gcd(a,b);
    return a*b/d;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        ll a,b;
        cin >> a >> b;
        cout << lcm(a,b) << endl;
    }
}