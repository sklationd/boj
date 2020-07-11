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

    vector<vector<int>> list;
    for(i=0;i<N;i++){
        vector<int> pair;
        int start, end;
        cin >> start >> end;
        pair.push_back(start);
        pair.push_back(end);
        list.push_back(pair);
    }

    // sorting with descending order of termination time
    sort(list.begin(), list.end(), [](vector<int> l, vector<int> r) -> bool
    {
        if(l[1] == r[1])
            return l[0] < r[0];
        return l[1] < r[1];
    });

    int count = 1;
    int endtime = list[0][1];
    for(i=1;i<N;i++){
         if(endtime <= list[i][0]){
             count++;
             endtime = list[i][1];
         }
    }
    cout << count;
}