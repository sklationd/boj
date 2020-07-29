#include <iostream>
#include <cmath>
#include <unordered_map>

typedef long long int ll;
using namespace std;

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

int main(){
    int P,B,N;
    while(scanf("%d %d %d", &P, &B, &N) != EOF){
        int result = dlog(P,B,N);
        if(result != -1)
            printf("%d\n", dlog(P,B,N));
        else
            printf("no solution\n");
    }
    return 0;
}