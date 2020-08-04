#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

typedef unsigned long long int ll;

ll gcd(ll a, ll b){
    ll r = a%b;
    while(r){
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}

ll abs_sub(ll a, ll b){
    if (a > b)
        return a - b;
    else
        return b - a;    
}

inline ll addmod(__uint128_t x, __uint128_t y, __uint128_t m) {
    return (x+y) % m;
}
 
inline ll mulmod(__uint128_t x, __uint128_t y, __uint128_t m) {
    return (x*y) % m;
}

ll power(ll a, ll n, ll p){
    ll result = 1;
    while(n>0){
        if(n%2 == 1)
            result = mulmod(result, a, p);
        a = mulmod(a,a,p);
        n/=2;
    }
    return result;
}

bool MR(ll a, ll n){
    ll k = n-1;
    while(k%2 == 0){
        ll p = power(a,k,n);
        if(p == n-1)
            return true;
        k/=2;
    }

    ll t = power(a, k, n);
    return t == n-1 || t == 1;
}

bool PT(ll n){
    if(n <= 1)
        return false;

    if(n < 100000000ULL) {
        for (ll i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    ll list[7] = {2,325,9375,28178,450775,9780504,1795265022};

    for(int i=0;i<7;i++){
        if(!MR(list[i],n)){
            return false;
        }
    }
    return true;
}

ll f(ll x, ll c, ll n){
    ll r = mulmod(x,x,n);
    r = (r+c) % n;
    return r;
}

ll PR(ll n){
    if(n==1)
        return n;
    if(n%2==0)
        return 2;

    ll x = (rand()%(n-2)) + 2;
    ll y = x;
    ll d = 1;
    ll c = (rand()%(n-1)) + 1;

    while(d==1){
        x = f(x,c,n);
        y = f(f(y,c,n),c,n);
        d = gcd(abs_sub(x,y),n);
    }

    if(d == n)
        return PR(n);
    else
        return d;
}

void factorization(ll n, vector<ll> &factors){
    while(n!=1){
        // if n is prime, return
        if(PT(n)){
            factors.push_back(n);
            break;
        }
        
        // find one divisor that is less than n
        ll d = PR(n);

        // if that divisor is prime, push that prime in vector and continue
        if(PT(d)){
            factors.push_back(d);
        } 
        // else factorize d
        else 
            factorization(d,factors);
        
        n/=d;
    }
}

int main(){
    srand(100);

    ll n;
    cin >> n;
    vector<ll> factors;
    factorization(n,factors);
    sort(factors.begin(), factors.end());
    for(int i=0;i<factors.size();i++)
        cout << factors[i] << "\n";
}