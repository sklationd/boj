#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int A[101][101] = {0,};
    int B[101][101] = {0,};
    int res[101][101] = {0,};
    int N,M,K;
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for (int j=0;j<M;j++){
            cin >> A[i][j];
        }
    }
    cin >> M >> K;
    for(int i=0;i<M;i++){
        for (int j=0;j<K;j++){
            cin >> B[i][j];
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            for(int k=0;k<M;k++){
                res[i][j]+=A[i][k]*B[k][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        for(int j=0;j<K;j++){
            cout << res[i][j] << " ";
        }
        cout << "\n";
    }
}