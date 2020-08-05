#include <iostream>
#include <vector>

#define MAX_D 150000
using namespace std;

int d(pair<int,int> a, pair<int,int> b){   
    return abs(a.first - b.first) + abs(a.second - b.second); 
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N,c,i,j,k;
    cin >> T;
    for(c=0;c<T;c++){
        cin >> N;
        vector<pair<int,int>> store(N+2);
        for(i=0;i<N+2;i++){
            cin >> store[i].first >> store[i].second;
        }

        vector<vector<int>> dist(N+2, vector<int>(N+2,MAX_D));
        for(i=0;i<N+2;i++){
            for(j=0;j<N+2;j++){
                int temp_d = d(store[i],store[j]);
                if(temp_d > 1000)
                    temp_d = MAX_D;
                dist[i][j] = temp_d;
            }
        }

        for(k=1;k<N+1;k++){
            for(i=0;i<N+2;i++){
                for(j=0;j<N+2;j++){
                    if((dist[i][j] > dist[i][k] + dist[k][j])){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }

        if(dist[0][N+1] == MAX_D)
            cout << "sad" << "\n";
        else 
            cout << "happy" << "\n";
    }
    return 0;
}