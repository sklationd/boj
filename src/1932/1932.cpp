#include <iostream>

int buf[501][501] = {0,};
int result[501][501] = {0,};
using namespace std;

int max2(int a, int b){
    return a<b?b:a;
}

int solve(int n, int i){
    // printf("%d %d\n", n,i);
    if(n==0){
        result[0][0] = buf[0][0];
        return result[0][0];
    } else {
        if(result[n][i]!=0){
            return result[n][i];
        } else {
            if(i==0){
                result[n][i] = solve(n-1,i) + buf[n][i];
                return result[n][i];
            }
            else if(i==n){
                result[n][i] = solve(n-1,i-1) + buf[n][i];
                return result[n][i];
            } else {
                int left = solve(n-1,i-1) + buf[n][i];
                int right = solve(n-1,i) + buf[n][i];
                result[n][i] = max2(left, right);
                return result[n][i];
            }
        }
    }
}


int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            cin >> buf[i][j];
        }
    }

    // bottop up to reducing memory usage
    for(i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            solve(i,j);
        }
    }
    
    // finding maximal value of last row
    int max = 0;
    for(i=0;i<N;i++){
        if(result[N-1][i] > max)
            max = result[N-1][i];
    }
    printf("%d", max);
}