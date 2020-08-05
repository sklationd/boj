#include <iostream>
#include <vector>

#define MAX_INT 20000
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i,j,k;
    cin >> N;

    vector<vector<int>> map(N,vector<int>(N,MAX_INT));
    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            int d;
            cin >> d;
            if(d)
                map[i][j] = d;
        }
    }
    
    for(k=0;k<N;k++){
        for(i=0;i<N;i++){
            for(j=0;j<N;j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            if(map[i][j] == MAX_INT){
                cout << 0 << " ";
            } else {
                cout << 1 << " ";
            }
        }
        cout << endl;
    }


    return 0;
}