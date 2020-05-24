#include <iostream>
#include <cstring>
#define D 1000
typedef long long int ll;
using namespace std;

void MatMul(int N, ll (*A)[6], ll (*B)[6], ll (*C)[6]){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            for(int k=0;k<N;k++){
                C[i][j]+=A[i][k]*B[k][j];
                C[i][j]%=D;
            }
        }
    }
}

void MatPow(int N, ll (*A)[6], ll B, ll (*C)[6]){
    if(B==1){
        memcpy(C,A,sizeof(ll)*36);
    }
    else if(B==2){
        MatMul(N, A, A, C);
    }
    else if(B%2){
        ll T[6][6] = {0,};
        ll T2[6][6] = {0,};
        MatPow(N, A, B/2, T);
        MatMul(N, T, T, T2);
        MatMul(N, T2, A, C);
    } else if(B%2==0){
        ll T[6][6] = {0,};
        MatPow(N, A, B/2, T);
        MatMul(N, T, T, C);
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    ll r[6][6] = {0,};
    ll result[6][6] = {0,};
    ll N,B;
    cin >> N >> B;

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> r[i][j];
        }
    }
    MatPow(N, r,B,result);

    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cout << result[i][j] % 1000 << " ";
        }
        cout << "\n";
    }
}