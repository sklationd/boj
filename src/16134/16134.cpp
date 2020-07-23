#include <iostream>

#define P 1000000007
#define MAX_N 1000001

using namespace std;

typedef unsigned long long int ll;

ll pow(ll a,int n){
    if(n==1) return a;
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
    R = max(R,N-R);
    ll num = 1;
    ll deno = 1;
    for(i=1;i<N-R+1;i++){
        num = (num*(N-i+1))%P;
        deno = (deno*i)%P;
    }
    ll inverse = inv(deno);
    ll result = (num * inverse) % P;
    cout << result << "\n";
}