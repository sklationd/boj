#include <iostream>
#include <assert.h>

#define D 10007

using namespace std;

int dp[1002][1002] = {0,};

int solve(int n, int k){
    if(dp[n][k]!=0){
        return dp[n][k];
    } else if (n==0 || n<k){
        dp[n][k] = 0;
    } else if(k==0){
        dp[n][k] = 1;
    } else if(k==1){
        dp[n][k] = n;
    } else {
        dp[n][k] = (solve(n-1, k-1)%D + solve(n-1,k)%D)%D;
    }
    return dp[n][k];
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K;
    cin >> N >> K;

    for(int i=1;i<=N;i++)
        for(int j=0;j<=i;j++)
            solve(i,j);
    cout << solve(N,K);
}