#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(pair<int, int> &a, pair<int, int> &b){
    return a.first < b.first;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;

    vector<pair<int, int>> v(N);
    vector<int> c(N,-1);

    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        v[i] = make_pair(temp,i);
    }

    sort(v.begin(), v.end(), cmp);

    int count = 0;
    for(i=0;i<N;i++){
        int index = v[i].second;
        c[index] = count;

        int memory=v[i].first;
        while(i<N-1 && v[i+1].first == memory)
            c[v[++i].second] = count;
        
        count++;
    }

    for(i=0;i<N;i++){
        cout << c[i] << " ";
    }
}