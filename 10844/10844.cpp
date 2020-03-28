#include <iostream>
#define DIVIDER 1000000000
using namespace std;

int result[101][11]={0,};

int main(){
    int N,i,j;
    cin >> N;
    if(N==1){
        cout << 9;
        return 0;
    }
    result[0][0] = 0;
    for(i=1;i<10;i++)
        result[0][i] = 1;
    for(i=1;i<N;i++){
        for(j=0;j<10;j++){
            if(j==0)
                result[i][j] = result[i-1][j+1];
            else if(j==9)
                result[i][j] = result[i-1][j-1];
            else 
                result[i][j] = (result[i-1][j-1] + result[i-1][j+1])%DIVIDER;
        }
    }
    long long int sum = 0;
    for(i=0;i<10;i++){
        sum+=result[N-1][i];
        sum%=DIVIDER;
    }
    cout << sum;
}

