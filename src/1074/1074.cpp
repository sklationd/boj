#include <iostream>
using namespace std;

static int log2 (int number) { 
    int logCount = 0; 
    if(1<<16 <= number) { 
        logCount += 16; number >>= 16; 
    } if(1<<8 <= number) {
        logCount += 8; number >>= 8; 
    } if(1<<4 <= number) { 
        logCount += 4; number >>= 4; 
    } if(1<<2 <= number) { 
        logCount += 2; number >>= 2; 
    } 
    return logCount + (2 <= number ? 1 : 0); 
}

int main(){
    int N,r,c;
    cin >> N >> r >> c;
    int result = 0;
    while(c != 0){
        int log_col = log2(c);
        int offset = 2*log_col;
        int col_offset = 1<<log_col;
        result += 1<<offset;
        c -= col_offset;
    }

    while(r != 0){
        int log_row = log2(r);
        int offset = 2*log_row;
        int row_offset = 1<<log_row;
        result += 1<<(offset+1);
        r -= row_offset;
    }

    cout << result << endl;
}