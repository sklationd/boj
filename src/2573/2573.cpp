#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

int N,M,C=0;
int map[301][301] = {0,};
int mark[301][301] = {0,};    

// Fast IO
char buf[1 << 17];
char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
int readInt() {
	int t, r = read() & 15;
	while ((t = read()) & 16) r = r * 10 + (t & 15);
	return r;
}

// Sea?
int sea(int i, int j){
    if(map[i][j]==0)
        return 1;
    else
        return 0;    
}

int meltCount(int i, int j){
    int seaCount = sea(i-1,j) + sea(i+1,j) + sea(i,j-1) + sea(i,j+1);
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

int bfs(queue<tuple<int, int, int>> &meltC){
    bool mark[301][301] = {false};
    queue<pair<int, int>> Q;
    pair<int, int> P;

    for(int i=1;i<N-1;i++){
        for(int j=1;j<M-1;j++){
            if(map[i][j]!=0){
                P.first = i;
                P.second = j;
            }
        }
    }

    Q.push(P);
    mark[P.first][P.second] = true;

    int count = 0;
    while(!Q.empty()){
        pair<int, int> ib = Q.front(); Q.pop();
        count++;

        int r = ib.first;
        int c = ib.second;

        meltC.push(make_tuple(r,c,meltCount(r, c)));

        if(!mark[r-1][c] && map[r-1][c]!=0) {
            Q.push(make_pair(r-1,c));
            mark[r-1][c] = true;
        }
        if(!mark[r+1][c] && map[r+1][c]!=0) {
            mark[r+1][c] = true;
            Q.push(make_pair(r+1,c));
        }
        if(!mark[r][c-1] && map[r][c-1]!=0) {
            mark[r][c-1] = true;
            Q.push(make_pair(r,c-1));
        } 
        if(!mark[r][c+1] && map[r][c+1]!=0) {
            mark[r][c+1] = true;
            Q.push(make_pair(r,c+1));
        }
    }
    return count;
}

void print_map(){
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cout << map[i][j] << " ";
        }
        cout << endl;
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    N = readInt();
    M = readInt();

    vector<pair<int,int>> iceberg;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            map[i][j] = readInt();
            if(map[i][j]) C++;
        }
    }

    queue<tuple<int, int, int>> count;
    int time = 0;

    while(C!=0){

        if(C!=0 && bfs(count) < C){
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