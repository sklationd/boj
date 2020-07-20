#include <iostream>
#include <vector>

using namespace std;

int result[12] = {1,2,4,};

int dp(int n){
    if(result[n]!=0) return result[n];
    else return dp(n-3) + dp(n-2) + dp(n-1);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    vector<int> v(N);
    for(i=0;i<N;i++){
        cin >> v[i];
    }

    for(i=0;i<N;i++){
        cout << dp(v[i]-1) << endl;
    }

}