#include <iostream>
#define D 10007

using namespace std;

int dp[1001] = {1,3,};

int dp_func(int n){
    if(dp[n-1]!=0) 
        return dp[n-1];
    return (dp[n-1] = (dp_func(n-1) + dp_func(n-2)*2) % D);
}

int main(){
    int N,i;
    cin >> N;   
    cout << dp_func(N);
}