#include <iostream>
#define D 1000000007

typedef long long int ll;

using namespace std;

ll fact[4000001] = {1,1,0,};

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

ll factorial(int N){
    if(fact[N])
        return fact[N];
    else 
        return fact[N] = (factorial(N-1)*N)%D;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;

    for(int i=2;i<=N;i++){
        factorial(i);
    }

    ll A,B;
    A = factorial(N);
    B = (factorial(K)*factorial(N-K))%D;
    cout << (A*power(B,D-2,D))%D;

}