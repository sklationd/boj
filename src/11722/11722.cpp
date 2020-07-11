#include <iostream>

int array[1001] = {0,};
int dp[1001] = {1,0};

using namespace std;
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

    for(i=1;i<N;i++){
        int max = 1;
        for(j=0;j<i;j++){
            if(array[j]>array[i]){
                if(dp[j] + 1 > max){
                    max = dp[j] + 1;
                }
            }
        }
        dp[i] = max;
    }

    int max = 0;
    for(i=0;i<N;i++){
        if(max < dp[i])
            max = dp[i];
    }
    
    printf("%d",max);

}