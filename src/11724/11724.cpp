#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N,M;

void check(vector<vector<int>> &v, vector<bool> &chk, int a){
    chk[a] = true;
    for(int i=0;i<v[a].size();i++){
        if(!chk[v[a][i]]){
            chk[v[a][i]] = true;
            check(v, chk, v[a][i]);
        }
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> N >> M;
    vector<vector<int>> v(N);
    vector<bool> chk(N,false);

    for(i=0;i<M;i++){
        int v1,v2;
        cin >> v1 >> v2;
        v[v1-1].push_back(v2-1);
        v[v2-1].push_back(v1-1);
    }

    int count = 0;
    for(i=0;i<N;i++){
        if(!chk[i]){
            check(v, chk, i);
            count++;
        }
    }

    cout << count << endl;
}