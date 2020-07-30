#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

void p_base(vector<ll> &output, ll n, ll p){
    while(n!=0){
        output.push_back(n%p);
        n/=p;
    }
}

ll power(ll a, ll n, ll p){
    if(n==0) return 1;
    else {
        ll half = power(a,n/2,p);
        ll result = (half*half) % p;
        if(n%2) result = (result * a) % p;
        return result;
    }
}

ll inv(ll a, ll p){
    return power(a,p-2,p);
}

ll nCm(ll n, ll m, ll p){
    if(n<m) return 0;
    m = min(m,n-m);
    ll num = 1;
    ll den = 1;
    for(int i=1;i<=m;i++){
        num = (num*(n-m+i)) % p;
        den = (den*i) % p;
    }
    ll result = (num*inv(den,p)) % p;
    return result;
}

int main(){
    ll N,K,M; cin >> N >> K >> M;
    vector<ll> nonp;
    vector<ll> konp;
    p_base(nonp, N, M);
    p_base(konp, K, M);
    while(nonp.size() > konp.size())
        konp.push_back(0);

    ll result = 1;
    for(int i=0;i<nonp.size();i++){
        ll result_i = nCm(nonp[i], konp[i], M);
        result = (result * result_i) % M;
        if(result_i == 0){
            break;
        }
    }
    cout << result << "\n";
}