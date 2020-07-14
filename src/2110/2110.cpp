#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,K,i,j;
    cin >> N >> K;
    vector<int> v;
    v.reserve(N);

    int min = 1000000000;
    int max = 0;
    for(i=0;i<N;i++){
        int x;
        cin >> x;
        v.push_back(x);
        if(max < x)
            max = x;
        if(min > x)
            min = x;
    }

    sort(v.begin(), v.end());

    // binary search boundary
    int b_max = max - min;
    int b_min = 1;
    int ind = b_min;
    int answer = 0;

    while(b_min<=b_max){
        int mid = (b_min + b_max) / 2;

        int count = 1;
        int distance;
        int start = v[0];

        // Count the number of router
        for(i=0;i<N;i++){
            if((distance = (v[i] - start))>=mid){
                count++;
                start = v[i];
            }
        }

        // Lower
        if(count < K){
            b_max = mid-1;
        }

        // Upper
        else if(count >= K) {
            b_min = mid + 1;
            answer = mid;
        } 

    }

    cout << answer << endl;

}