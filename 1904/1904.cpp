#include <iostream>
#define DIVIDER 15746
using namespace std;

int dp[1000001] = {0,};

int tile(int n){
    if(n==1 || n==2){
        dp[n-1] = n;
        return dp[n-1];
    }
    else if(dp[n-1])
        return dp[n-1];
    else {
        dp[n-1] = (tile(n-1) + tile(n-2))%DIVIDER;
        return dp[n-1];
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=1;i<=N;i++){
        tile(i);
    }
    cout << tile(N);
}