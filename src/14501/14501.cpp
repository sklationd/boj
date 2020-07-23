#include <iostream>
#include <vector>

using namespace std;

int N;

int work(int n, vector<int> &dp, vector<int> &T, vector<int> &P){ // from day n what is the maximum?
    if(n > N) {
        return 0;
    }

    if(dp[n-1]!=0){
        return dp[n-1];
    }

    // work day n
    int cost = T[n-1];
    int reward = P[n-1];
    int work_now;
    if(cost + n - 1 <= N)
        work_now = reward + work(n+cost, dp, T, P);
    else
        work_now = 0;       
         
    // not work day n
    int work_later = work(n+1, dp, T, P);

    int best = max(work_now, work_later);
    dp[n-1] = best;

    return best;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i;
    cin >> N;

    vector<int> T(N,0);
    vector<int> P(N,0);
    vector<int> DP(N,0);

    for(i=0;i<N;i++){
        int t,p;
        cin >> t >> p;
        T[i] = t;
        P[i] = p;
    }

    cout << work(1, DP, T, P) << "\n";
}