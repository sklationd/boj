#include <iostream>

using namespace std;

int N,L;
int map[101][101] = {0,};

bool row_check(int i){
    int prev = map[i][0];
    int count = 1;
    for(int j=1;j<N;j++){
        if(map[i][j] - prev == 1){
            if(count >= L){
                count = 1;
                prev = map[i][j];
            } else {
                return false;
            }
        } else if(map[i][j] - prev == - 1){
            for(int k=0;k<L;k++){
                if(j+k > N-1 || map[i][j+k] != prev - 1)
                    return false;
            }
            j+=L-1;
            count=0;
            prev--;
            continue;
        } else if(abs(map[i][j] - prev) > 1){
            return false;
        } else {
            count++;
            continue;
        }
    }
    return true;
}

bool col_check(int j){
    int prev = map[0][j];
    int count = 1;
    for(int i=1;i<N;i++){
        if(map[i][j] - prev == 1){
            if(count >= L){
                count = 1;
                prev = map[i][j];
            } else {
                return false;
            }
        } else if(map[i][j] - prev == - 1){
            for(int k=0;k<L;k++){
                if(i+k > N-1 || map[i+k][j] != prev - 1)
                    return false;
            }
            i+=L-1;
            count=0;
            prev--;
            continue;
        } else if(abs(map[i][j] - prev) > 1){
            return false;
        } else {
            count++;
            continue;
        }
    }
    return true;
}

bool check(int i, bool row){
    if(row){
        return row_check(i);
    } else {
        return col_check(i);
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> N >> L;

    for(i=0;i<N;i++){
        for(j=0;j<N;j++){
            cin >> map[i][j];
        }
    }

    int count = 0;
    for(i=0;i<N;i++){
        if(row_check(i)){
            count++;
        }
    }

    for(i=0;i<N;i++){
        if(col_check(i)){
            count++;
        }
    }

    cout << count << endl;
}