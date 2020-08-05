#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <tuple>

using namespace std;

int M, N, H, C = 0;
int map[101][101][101] = {0,};

pair<int,int> bfs(queue<tuple<int,int,int>> & Q){
    int day = 0;
    int count = Q.size();
    while(!Q.empty()){
        if(C == count){
            break;
        }
        int s = Q.size();
        if(s>0)
            day++;
        for(int i=0;i<s;i++){
            int r = get<0>(Q.front());
            int c = get<1>(Q.front());
            int h = get<2>(Q.front()); 
            Q.pop();
            
            if(r>0 && map[r-1][c][h]==0){
                Q.push(make_tuple(r-1,c,h));
                map[r-1][c][h] = 1;
                count++;
            }
            if(r<N-1 && map[r+1][c][h]==0){
                Q.push(make_tuple(r+1,c,h));
                map[r+1][c][h] = 1;
                count++;
            }
            if(c>0 && map[r][c-1][h]==0){
                Q.push(make_tuple(r,c-1,h));
                map[r][c-1][h] = 1;
                count++;
            }
            if(c<M-1 && map[r][c+1][h]==0){
                Q.push(make_tuple(r,c+1,h));
                map[r][c+1][h] = 1;
                count++;
            }
            if(h>0 && map[r][c][h-1]==0){
                Q.push(make_tuple(r,c,h-1));
                map[r][c][h-1] = 1;
                count++;
            }
            if(h<H-1 && map[r][c][h+1]==0){
                Q.push(make_tuple(r,c,h+1));
                map[r][c][h+1] = 1;
                count++;
            }   
        }
    }
    return make_pair(count,day);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j,k;
    cin >> M >> N >> H;
    queue<tuple<int,int,int>> Q;

    for(k=0;k<H;k++){
        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                cin >> map[i][j][k];
                if(map[i][j][k]>=0){
                    C++;
                }
                if(map[i][j][k]==1){
                    Q.push(make_tuple(i,j,k));
                }
            }
        }
    }

    pair<int,int> days = bfs(Q);
    if(days.first != C){
        cout << -1 << "\n";
    } else {
        cout << days.second << "\n";
    }

    return 0;
}