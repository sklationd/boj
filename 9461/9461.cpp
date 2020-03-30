#include <iostream>
using namespace std;

long long int dp[101] = {0,};

long long int tile(int n){
    if(n==1 || n==2 || n==3){
        dp[n-1] = 1;
        return 1;
    } else if(n==4){
        dp[n-1] = 2;
        return 2;
    } else if(n==5){
        dp[n-1] = 2;
        return 2;
    }
    else if(dp[n-1]) return dp[n-1];
    else {
        dp[n-1] = tile(n-1) + tile(n-5);
        return dp[n-1];
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,i;
    cin >> T;
    for(i=1;i<=100;i++) tile(i);
    for(i=0;i<T;i++){
        int temp;
        cin >> temp;
        cout << tile(temp) << "\n";
    }
}