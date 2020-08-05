#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N;

int map[26][26] = {0,};
bool mark[26][26] = {false,};

int bfs(int r, int c){
    queue<pair<int,int>> Q;
    Q.push(make_pair(r,c));
    mark[r][c] = true;
    int count = 1;

    while(!Q.empty()){
        int s = Q.size();
        for(int i=0;i<s;i++){
            int row = Q.front().first;
            int col = Q.front().second;
            Q.pop();

            if(row>0 && map[row-1][col] && !mark[row-1][col]){
                Q.push(make_pair(row-1,col));
                count++;
                mark[row-1][col] = true;
            }

            if(row<N-1 && map[row+1][col] && !mark[row+1][col]){
                Q.push(make_pair(row+1,col));
                count++;
                mark[row+1][col] = true;
            }

            if(col>0 && map[row][col-1] && !mark[row][col-1]){
                Q.push(make_pair(row,col-1));
                count++;
                mark[row][col-1] = true;
            }

            if(col<N-1 && map[row][col+1] && !mark[row][col+1]){
                Q.push(make_pair(row,col+1));
                count++;
                mark[row][col+1] = true;
            }
        }
    }
    return count;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> N;
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            char c;
            cin >> c;
            map[i][j] = c-'0';
        }
    }

    vector<int> count;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j]==1 && !mark[i][j]){
                count.push_back(bfs(i,j));
            }
        }
    }

    sort(count.begin(), count.end());

    cout << count.size() << "\n";
    for(i=0;i<count.size();i++){
        cout << count[i] << "\n";
    }

    return 0;
}