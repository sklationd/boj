#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    vector<int> cost;
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        cost.push_back(temp);
    }
    sort(cost.begin(), cost.end());
    int sum = 0;
    for(i=0;i<N;i++){
        for(int j=0;j<=i;j++){
            sum+=cost[j];
        }
    }
    cout << sum;
}
