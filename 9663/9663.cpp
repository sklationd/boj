#include <iostream>

using namespace std;

int checkboard[16][16] = {0,};
int N;
int result = 0;

bool check(int row, int col){
    int i=0;
    int j=0;

    for(i=0;i<col;i++)
        if(checkboard[row][i])
            return false;
    // upper
    for(i=row,j=col;i<N && j>=0;i++,j--)
        if(checkboard[i][j])
            return false;

    // lower
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(checkboard[i][j])
            return false;
            
    return true;
}

bool solve(int col)
{
    if (col >= N){
        result++;
        return true;
    }
    bool res = false;
    for(int i=0;i<N;i++){
        if(check(i,col)){
            checkboard[i][col] = 1;
            res = solve(col+1) || res;
            checkboard[i][col] = 0;
        }
    }

    return res;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    solve(0);
    printf("%d", result);
    
}