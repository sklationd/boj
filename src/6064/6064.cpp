#include <iostream>

using namespace std;

typedef long long int ll;

ll gcd(ll a, ll b){
    int r = a%b;
    while(r){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

ll lcm(ll a, ll b){
    return a*b/gcd(a,b);
}

// solve ax+by = d (gcd(a,b))
pair<ll,ll> EEA(ll a, ll b){
    ll s0 = 1;
    ll s1 = 0;
    ll t0 = 0;
    ll t1 = 1;
    ll r0 = a;
    ll r1 = b;
    ll q,temp;
    while(r1){
        ll q = r0/r1;
        // cal s
        temp = s0;
        s0 = s1;
        s1 = temp - s1*q;
        // cal t
        temp = t0;
        t0 = t1;
        t1 = temp - t1*q;
        // cal r
        temp = r0;
        r0 = r1;
        r1 = temp - r0*q;
    }
    return make_pair(s0,t0);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        ll M,N,x,y;
        cin >> M >> N >> x >> y;
        ll d = gcd(M,N);
        ll l = lcm(M,N);
        if((x-y)%d !=0){
            cout << -1 << "\n";
            continue;
        } else {
            pair<ll,ll> T = EEA(M,N);
            ll sol = (T.first*(y-x)/d)*M+x;
            while(sol <= 0) sol+=l;
            while(sol > l) sol-=l;
            cout << sol << "\n";
        }
    }
}