#include <iostream>
#include <cmath>
#include <unordered_set>
#include <unordered_map>
#include <string>
#define BF 800
typedef long long int ll;

using namespace std;

int gcd(int a, int b){
    int q = a/b;
    int r = a%b;
    if(r){
        return gcd(b,r);
    } else {
        return b;
    }
}

ll power(ll a, int n, ll p){
    if(n==0) return 1;
    else {
        ll half = power(a,n/2,p);
        ll result = (half * half) % p;
        if(n%2)
            result = (result * a) % p;
        return result;
    }
}

void factorization(unordered_set<int> &factors, int n){
    while(n%2==0){
        n /= 2;
        factors.insert(2);
    }

    for(int i=3;i*i<n;i+=2){
        while(n%i==0){
            n /= i;
            factors.insert(i);
        }
    }

    if(n > 2)
        factors.insert(n);
}

// find primitive root of prime p
int findPrimitive(int p){
    // euler totient
    int phi = p-1;

    unordered_set<int> factors;

    factorization(factors, phi);

    for(int r=2; r<=phi;r++){
        bool result = true;
        for(auto it = factors.begin();it!=factors.end();it++){
            if(power(r,phi/(*it),p) == 1){
                result = false;
                break;
            }
        }
        if(result){
            return r;
        }
    }
    return -1;
}

int dlog(int P, int B, int N){
    int m = ceil(sqrt(P-1));
    unordered_map<ll, int> ss;
    for(int i=0;i<m;i++){
        ss.insert(make_pair(power(B,i,P),i));
    }
    ll factor = power(B, P-m-1, P);
    
    int x;
    int y = N;
    for(int i=0;i<m;i++){
        auto it=ss.find(y);
        if(it!=ss.end()){
            return i*m + it->second;
        }
        y = (y*factor)%P;
    }
    return -1;
}

ll solve(ll p, ll a, ll m){
    if(a == 0)
        return p;
    if(p < BF){
        int n;
        for(n=1;n<=p*(p-1);n++){
            if((power(n,n,p) + power(n,m,p))%p == a)
                break;
        }
        if(n>p*(p-1))
            return -1;
        return n;
    } else {
        ll origin_x = findPrimitive(p);
        ll x = origin_x;

        // corner case
        int K;
        int k=1;
        while((K = power(x,m,p))%p == a){
            while(gcd(++k,p-1)!=1 && (k*m)%p != (m % p) && k < (p-1));
            if(k >= (p-1)) return -1;
            x = power(origin_x,k,p);
        }
        ll rhs = a - K < 0 ? a - K + p : a - K;
        ll y = dlog(p,x,rhs);
        return ((y - x)*p + x) % (p*(p-1));
    }
}

int main(){
    int d;
    cin >> d;
    for(int i=0;i<d;i++){
        int p,a,m;
        cin >> p >> a >> m;
        ll result = solve(p,a,m);
        if(result == -1)
            cout << "NIE" << "\n";
        else
            cout << "TAK " << result << "\n";        
    }
}