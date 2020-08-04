#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long int ll;

ll power(ll a, ll n, ll p){
    ll result = 1;
    while(n>0){
        if(n%2 == 1)
            result = (result * a) % p;
        a = (a * a) % p;
        n/=2;
    }
    return result;
}


bool MR(ll a, ll n){
    ll k = n-1;
    while(k%2 == 0){
        if(power(a,k,n) == n-1)
            return true;
        k/=2;
    }
    ll t = power(a, k, n);
    return t == n-1 || t == 1;
}


bool PT(ll n){
    if(n <= 1)
        return false;

    if(n < 10000ULL) {
        for (ll i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    ll list[3] = {2,7,61};
    for(int i=0;i<3;i++){
        if(!MR(list[i],n))
            return false;
    }
    return true;
}

ll find_next(ll n){
    while(!PT(n))
        n++;
    return n;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,i;
    cin >> N;
    for(i=0;i<N;i++){
        ll n;
        cin >> n;
        cout << find_next(n) << "\n";
    }
}