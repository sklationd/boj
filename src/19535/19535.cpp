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
    vector<vector<int>> V(N+1);
    vector<pair<int,int>> E(N-1);

    for(i=0;i<N-1;i++){
        int v1,v2;
        cin >> v1 >> v2;
        V[v1].push_back(v2);
        V[v2].push_back(v1);
        E[i].first = v1;
        E[i].second = v2;
    }

    ll D = 0;
    ll G = 0;

    for(i=1;i<=N;i++){
        if(V[i].size() >= 3) {
            ll s = V[i].size();
            G += s*(s-1)*(s-2) / 6 ;
        }
    }

    for(i=0;i<N-1;i++){
        int v1,v2;
        v1 = E[i].first;
        v2 = E[i].second;
        ll l = V[v1].size() - 1;
        ll r = V[v2].size() - 1;
        D += l * r;
    }

    if(D > 3*G)
        cout << "D" << endl;
    else if(D < 3*G) 
        cout << "G" << endl;
    else
        cout << "DUDUDUNGA" << endl;    
}