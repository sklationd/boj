#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N,M,C=0;
int map[301][301] = {0,};
int mark[301][301] = {true};
pair<int, int> iceberg;

int meltCount(int i, int j){
    int seaCount = 0;
    if(!map[i-1][j]) seaCount++;
    if(!map[i+1][j]) seaCount++;
    if(!map[i][j-1]) seaCount++;
    if(!map[i][j+1]) seaCount++;
    return seaCount;
}

// Melt
int melt(queue<tuple<int, int, int>> &count){
    int melted = 0;
    while(!count.empty()){
        int r = get<0>(count.front());
        int c = get<1>(count.front());
        map[r][c] = max(map[r][c]-get<2>(count.front()),0); count.pop(); 
        if(map[r][c] == 0)
            melted++;
    }
    return melted;
}

int bfs(queue<tuple<int, int, int>> &meltC, int t){
    queue<pair<int, int>> Q;
    pair<int, int> P;

    if(map[iceberg.first][iceberg.second]==0){
        for(int i=1;i<N-1;i++){
            for(int j=1;j<M-1;j++){
                if(map[i][j]!=0){
                    iceberg.first = i;
                    iceberg.second = j;
                }
            }
        }
    }

    Q.push(iceberg);
    mark[iceberg.first][iceberg.second]++;

    int count = 0;
    while(!Q.empty()){
        pair<int, int> ib = Q.front(); Q.pop();
        count++;

        int r = ib.first;
        int c = ib.second;

        meltC.push(make_tuple(r,c,meltCount(r, c)));

        if(mark[r-1][c]<t+1 && map[r-1][c]!=0) {
            Q.push(make_pair(r-1,c));
            mark[r-1][c]++;
        }
        if(mark[r+1][c]<t+1 && map[r+1][c]!=0) {
            mark[r+1][c]++;
            Q.push(make_pair(r+1,c));
        }
        if(mark[r][c-1]<t+1 && map[r][c-1]!=0) {
            mark[r][c-1]++;
            Q.push(make_pair(r,c-1));
        } 
        if(mark[r][c+1]<t+1 && map[r][c+1]!=0) {
            mark[r][c+1]++;
            Q.push(make_pair(r,c+1));
        }
    }
    return count;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;
    
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin >> map[i][j];
            if(map[i][j]) {
                C++;
            }
        }
    }

    iceberg = make_pair(1,1);
    queue<tuple<int, int, int>> count;
    int time = 0;

    while(C!=0){

        if(C!=0 && bfs(count,time) < C){
            break;
        }

        int mc = melt(count);
        C -= mc;

        time++;
    }

    if(C)
        cout << time << "\n";
    else
        cout << "0\n";
}