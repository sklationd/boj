#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;
int main(void){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<ll> v;

    ll N,K,i;
    cin >> N >> K;
    v.reserve(N);
    ll sum = 0;
    for(i=0;i<N;i++){
        cin >> v[i];
        sum += v[i];
    }
    
    ll end = sum / K + 1;
    ll ind = end/2;

    while(1){
        ll count = 0;
        ll prev_ind = ind;
        for(i=0;i<N;i++){
            count+=v[i]/ind;
        }
        if(count>=K){
            ind+=(end-ind)/2;
        } else {
            end = ind;
            ind = ind/2;
        }
        if(ind == prev_ind)
            break;
    }

    cout << ind << endl;
    return 0;
}