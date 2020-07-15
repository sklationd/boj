#include <iostream>
#include <cmath>
#include <limits.h> 

#define MAX_H 256

using namespace std;

typedef long long int ll;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,B,i,j;
    short map[501][501] = {0,};

    int min_ = INT_MAX;
    int max_ = 0;

    cin >> N >> M >> B;

    // initialize map, min, max
    for(i=0;i<N;i++){
        for(j=0;j<M;j++){   
            cin >> map[i][j];
            if(map[i][j] > max_)
                max_ = map[i][j];
            if(map[i][j] < min_)
                min_ = map[i][j];
        }
    }

    max_ = min(MAX_H, max_);    
    min_ = min(MAX_H, min_);
    
    int result_time = INT_MAX;
    int result_height = max_;

    for(int h=max_;h>=min_;h--){
        int remain = B;
        int work_time = 0;

        for(i=0;i<N;i++){
            for(j=0;j<M;j++){
                // Calculate difference between desired height and actual height
                int dH = h - map[i][j];
                // Blocks should be removed
                if(dH < 0){
                    work_time += abs(dH) * 2;
                    remain += abs(dH);
                }
                // We should stack more blocks
                else{
                    work_time += abs(dH);
                    remain -= abs(dH);
                }
            }
        }

        // Save result
        if(remain >= 0 && result_time > work_time) {
            result_time = work_time;
            result_height = h;
        }
    }

    cout << result_time << " " << result_height << endl;
}