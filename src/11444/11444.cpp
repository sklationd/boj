#include <iostream>
#include <cstring>
#define D 1000000007
typedef long long int ll;
using namespace std;

void MatMul(int N, ll (*A)[2], ll (*B)[2], ll (*C)[2]){
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

void MatPow(int N, ll (*A)[2], ll B, ll (*C)[2]){
    if(B==1){
        memcpy(C,A,sizeof(ll)*4);
    }
    else if(B==2){
        MatMul(N, A, A, C);
    }
    else if(B%2){
        ll T[2][2] = {0,};
        ll T2[2][2] = {0,};
        MatPow(N, A, B/2, T);
        MatMul(N, T, T, T2);
        MatMul(N, T2, A, C);
    } else if(B%2==0){
        ll T[2][2] = {0,};
        MatPow(N, A, B/2, T);
        MatMul(N, T, T, C);
    }
}
using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll N;
    cin >> N;
    if(N==1){
        cout << 1;
    } else {
        ll A[2][2] = {{1,1},{1,0}};
        ll R[2][2] = {0,};

        MatPow(2, A, N-1, R);

        cout << R[0][0];
    }
    
}