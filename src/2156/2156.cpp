#include <iostream>
using namespace std;

int amount[10001] = {0,};
int result[10001] = {0,};

int max3(int a, int b,int c){
    return a>b?(a>c?a:c):(b>c?b:c);
}

int solve(int i){
    if(result[i]!=0){
        return result[i];
    }

    if(i==0){
        result[i] = amount[i];
        return result[i];
    } else if (i==1) {
        result[i] = amount[i] + amount[i-1];
        return result[i];
    } else if (i==2) {
        result[i] = max3(amount[i-2] + amount[i-1], amount[i-1] + amount[i], amount[i-2] + amount[i]);
        return result[i];
    } else {
        result[i] = max3(solve(i-1), amount[i]+amount[i-1]+solve(i-3), amount[i] + solve(i-2));
        return result[i];
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
        cin >> amount[i];
    }
    for(i=0;i<N;i++){
        solve(i);
    }
    printf("%d", result[N-1]);

}