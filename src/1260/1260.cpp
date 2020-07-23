#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(vector<vector<int>> &G, int V, vector<bool> &check){
    check[V] = true;
    cout << V << " ";
    for(int i=0;i<G[V].size();i++){
        if(!check[G[V][i]]){
            dfs(G,G[V][i],check);
        }
    }
}

void bfs(vector<vector<int>> &G, int V, vector<bool> &check){
    check[V] = true;
    cout << V << " ";

    queue<int> Q;
    Q.push(V);

    while(Q.size()!=0){
        int length = Q.size();
        for(int i=0;i<length;i++){
            int home_V = Q.front(); Q.pop();
            for(int j=0;j<G[home_V].size();j++){
                int neigh_V = G[home_V][j];
                if(!check[neigh_V]){
                    check[neigh_V] = true;
                    Q.push(neigh_V);
                    cout << neigh_V << " ";
                }
            }
        }
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,V;
    cin >> N >> M >> V;

    vector<vector<int>> G(N+1);
    vector<bool> check_dfs(N+1,false);
    vector<bool> check_bfs(N+1,false);

    for(int i=0;i<M;i++){
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }

    for(int i=1;i<N+1;i++){
        sort(G[i].begin(),G[i].end());
        G[i].erase(unique(G[i].begin(), G[i].end()), G[i].end());
    }


    dfs(G,V,check_dfs);
    cout << "\n";
    bfs(G,V,check_bfs);
}