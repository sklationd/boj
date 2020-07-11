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
    vector<int> d;    
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        d.push_back(temp);
    }
    sort(d.begin(), d.end());
    cout << d[0]*d[N-1];
}