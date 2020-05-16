#include <iostream>
using namespace std;

int board[81] = {0,};

bool check(int row, int col, int num){
    int i,j;

    // row
    for(i=0;i<9;i++)
        if(board[9*row + i] == num) return false;

    // col
    for(i=0;i<9;i++)
        if(board[9*i + col] == num) return false;

    // box
    int boxIndexRow = row/3;
    int boxIndexCol = col/3;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            int index = boxIndexRow*27 + boxIndexCol*3 + i + j*9;
            if(board[index]==num) return false;
        }
    }

    return true;
}

void printSdoku(){
    for(int i=0;i<9;i++){
        for(int j=0;j<9;j++)
            printf("%d ", board[9*i+j]);
        printf("\n");       
    }
}

bool solve(int start){
    // find not filled box
    while(board[start])
        start++;

    if(start >= 81){
        printSdoku();
        return true;
    }

    for(int i=start;i<81;i++){
        int row = i/9;
        int col = i%9;
        for(int j=1;j<10;j++){
            if(check(row,col,j)){
                board[9*row + col] = j;
                if(solve(start+1)) return true;
                board[9*row + col] = 0;
            }       
        }
        return false;
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i;
    for(i=0;i<81;i++)
        cin >> board[i];

    solve(0);
}