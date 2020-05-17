#include <iostream>
#define MIN -100000001;
using namespace std;

int array[100001] = {0,};
int dp[100001] = {0,};
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> array[i];
    }

    dp[0] = array[0];

    for(i=1;i<N;i++){
        if(dp[i-1] + array[i] > array[i])
            dp[i] = dp[i-1] + array[i];
        else 
            dp[i] = array[i];
    }
    int max = -100000001;
    for(i=0;i<N;i++){
        if(dp[i] > max)
            max = dp[i];
    }
    cout << max;
}