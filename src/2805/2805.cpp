#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

ll max2(ll a, ll b){
    return a>b?a:b;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N,K;
    cin >> N >> K;

    vector<ll> v;
    v.reserve(N);

    ll max = 0;
    ll min = 0;

    for(ll i=0;i<N;i++){
        cin >> v[i];
        if(v[i] > max)
            max = v[i];
    }

    while(1){
        ll prev_min = min;

        ll sum = 0;
        for(ll i=0;i<N;i++){
            sum += max2((v[i] - min),0);
        }

        if(sum >= K)
            min = (max + min) / 2;
        else{
            max = min;
            min /= 2;
        }

        if(prev_min == min)
            break;

    }

    cout << min << endl;

}