#include <iostream>
#include <vector>
#define MAX_D 500
using namespace std;

typedef long long int ll;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,i,j,k;
    cin >> N >> M;

    vector<vector<int>> map(N,vector<int>(N,MAX_D));
    for(i=0;i<M;i++){
        int v1,v2;
        cin >> v1 >> v2;
        map[v1-1][v2-1] = 1;
        map[v2-1][v1-1] = 1; 
    }

    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(map[i][j]>map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
            }
        }
    }
    int min_ = MAX_D*100;
    int min_i = 0;
    for(i=0;i<N;i++){
        int sum_ = 0;
        for(j=0;j<N;j++){
            sum_+=map[i][j];
        }
        if(min_ > sum_){
            min_ = sum_;
            min_i = i;
        }
    }

    cout << min_i+1 << endl;
    return 0;
}