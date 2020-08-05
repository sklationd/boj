#include <iostream>
#include <queue>
using namespace std;

int N,M;
char map[101][101] = {0,};
bool mark[101][101] = {false, };
int bfs(){
    queue<pair<int, int>> Q;
    Q.push(make_pair(0,0));
    mark[0][0] = true;
    int count = 0;
    while(!Q.empty()){
        int s = Q.size();
        count++;
        for(int i=0;i<s;i++){
            int r = Q.front().first;
            int c = Q.front().second;
            Q.pop();

            if(r==N-1 && c==M-1){
                return count;
            }
            
            else {
                if(r>0 && map[r-1][c] && !mark[r-1][c]){
                    Q.push(make_pair(r-1,c));
                    mark[r-1][c] = true;
                }
                if((c>0 && map[r][c-1]) && !mark[r][c-1]){
                    Q.push(make_pair(r,c-1));
                    mark[r][c-1] = true;
                }
                if((r<N-1 && map[r+1][c]) && !mark[r+1][c]){
                    Q.push(make_pair(r+1,c));
                    mark[r+1][c] = true;
                }
                if((c<M-1 && map[r][c+1]) && !mark[r][c+1]){
                    Q.push(make_pair(r,c+1));
                    mark[r][c+1] = true;
                }
            }
        }
    }

    return -1;
}

int main(){
    int i,j;
    cin >> N >> M;
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            char c;
            cin >> c;
            map[i][j] = c-'0';
        }
    }
    cout << bfs() << endl;
    return 0;    
}