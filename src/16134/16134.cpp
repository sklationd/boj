#include <iostream>

#define P 1000000007
#define MAX_N 1000001

using namespace std;

typedef unsigned long long int ll;

int fact_dp[MAX_N] = {1,1,};
ll fact(int n){
    if(fact_dp[n]!=0) return fact_dp[n];
    fact_dp[n]=(n*fact(n-1)) % P;
    return fact_dp[n];
}

ll pow(ll a,int n){
    if(n==2) return (a*a) % P;
    if(n==3) return (((a*a)%P)*a)%P;
    else {
        ll half = pow(a,n/2) % P;
        ll sq = (half*half) % P;
        if(n%2){
            return (sq*a)%P;
        }
        return sq;
    }
}

ll inv(int n){
    return pow(n,P-2);
}

int main(){
    int N,R,i;
    cin >> N >> R;
    for(i=2;i<N;i++) fact(i);

    ll fact_n = fact(N);
    ll fact_r = fact(R);
    ll fact_n_r = fact(N-R);
    ll reverse = inv((fact_r * fact_n_r)%P);

    ll result = (fact_n * reverse) % P;
    cout << result << "\n";
}