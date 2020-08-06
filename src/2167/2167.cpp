#include <iostream>

using namespace std;

int readInt() {
    int ret = 0, flg = 1;
    char now = getchar();
    
    while (now == 10 || now == 32) now = getchar();
    if (now == '-') flg = -1, now = getchar();
    while (now >= 48 && now <= 57) {
        ret = ret * 10 + now - 48;
        now = getchar();
    }
    return ret * flg;
}

int main(){
    int T,N,M,r,c,k;
    int x,y,i,j;
    N = readInt();
    M = readInt();

    int map[301][301] = {0,};

    for(r=1;r<=N;r++){
        for(c=1;c<=M;c++){
            map[r][c] = readInt();
            map[r][c] += (map[r][c-1] + map[r-1][c] - map[r-1][c-1]); 
        }    
    }
    
    T = readInt();
    for(k=0;k<T;k++){
        int sum = 0;
        i = readInt();
        j = readInt();
        x = readInt();
        y = readInt();
        sum = map[x][y] - map[x][j-1] - map[i-1][y] + map[i-1][j-1];
        printf("%d\n",sum);
    }
    return 0;
}