#include <iostream>
#include <vector>
using namespace std;

typedef long long int ll;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    vector<pair<int,int>> E(N-1);
    vector<int> d_count(N+1,0);

    for(i=0;i<N-1;i++){
        int v1,v2;
        cin >> v1 >> v2;
        d_count[v1]++;
        d_count[v2]++;
        E[i].first = v1;
        E[i].second = v2;
    }

    ll D = 0;
    ll G = 0;

    for(i=1;i<=N;i++){
        if(d_count[i] >= 3) {
            ll s = d_count[i];
            G += s*(s-1)*(s-2)/6;
        }
    }

    for(i=0;i<N-1;i++){
        int v1,v2;
        v1 = E[i].first;
        v2 = E[i].second;
        ll l = d_count[v1] - 1;
        ll r = d_count[v2] - 1;
        D += l * r;
    }

    if(D > 3*G)
        cout << "D\n";
    else if(D < 3*G) 
        cout << "G\n";
    else
        cout << "DUDUDUNGA\n";    
    
    return 0;
}