#include <iostream>

using namespace std;

int cost[1001][3] = {0,};
int result[1001][3] = {0,};

int min3(int a, int b, int c){
    return a>b?(b>c?c:b):(a>c?c:a);
}

int min2(int a, int b){
    return a>b?b:a;
}

int solve(int n, int i){
    if(n==0){
        result[n][0] = cost[0][0];
        result[n][1] = cost[0][1];
        result[n][2] = cost[0][2];
        return result[n][i];
    } else {
        if(result[n][i]!=0){
            return result[n][i];
        } else {
            switch(i){
                case 0:
                    result[n][i] = cost[n][i] + min2(solve(n-1,1),solve(n-1,2));
                    return result[n][i];
                    break;
                case 1:
                    result[n][i] = cost[n][i] + min2(solve(n-1,0),solve(n-1,2));
                    return result[n][i];
                    break;
                case 2:
                    result[n][i] = cost[n][i] + min2(solve(n-1,0),solve(n-1,1));
                    return result[n][i];
                    break;
            }
        }
    }

}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<3;j++){
            cin >> cost[i][j];
        }
    }

    for(int i=0;i<N;i++){
        solve(i,0);
        solve(i,1);
        solve(i,2);
    }
    
    printf("%d",min3(solve(N-1, 0),solve(N-1, 1),solve(N-1, 2)));
}