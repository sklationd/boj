#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int map[1001][1001] = {0,};
int N,M;

bool check(){
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(map[i][j] == 0)
                return false;
        }
    }    
    return true;
}

int bfs(queue<pair<int, int>> &q){
    int sz = q.size();
    if(sz==0) return 0;
    for(int i=0;i<sz;i++){
        pair<int, int> elem = q.front();
        q.pop();
        
        int r = elem.first;
        int c = elem.second;

        if(c>0 && map[r][c-1]==0) {
            q.push(make_pair(r,c-1));
            map[r][c-1]=1;
        } 
        if(c<N-1 && map[r][c+1]==0){
            q.push(make_pair(r,c+1));
            map[r][c+1]=1;
        } 
        if(r>0 && map[r-1][c]==0) {
            q.push(make_pair(r-1,c));
            map[r-1][c]=1;
        }
        if(r<M-1 && map[r+1][c]==0) {
            q.push(make_pair(r+1,c));
            map[r+1][c]=1;
        }
    }

    return 1 + bfs(q);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> N >> M;
    queue<pair<int, int>> input;
    for(i=0;i<M;i++){
        for(j=0;j<N;j++){
            cin >> map[i][j];
            if(map[i][j] == 1)
                input.push(make_pair(i,j));
        }
    }

    int result = bfs(input);
    if(!check()) cout << -1 << endl;
    else cout << max(result - 1,0) << endl;

    return 0;
}