#include <iostream>

using namespace std;

int score[20][20] = {0,};
int N;
int res = -1;
int abuf[20] = {0,};

int abs(int a){
    return a>0?a:-a;
}

void scoring(){
    int aTeam = 0;
    int bTeam = 0;
    for(int i=0;i<N;i++){
        for(int j=i;j<N;j++){
            if(abuf[i] && abuf[j]) // aTeam
                aTeam += score[i][j] + score[j][i];
            else if(!(abuf[i] || abuf[j]))
                bTeam += score[i][j] + score[j][i];
        }
    }

    if(res < 0)
        res = abs(aTeam - bTeam);
    else if(res > abs(aTeam - bTeam)) 
        res = abs(aTeam - bTeam);
}

void solve(int length){
    int half = N/2;
    if(half == length){;
        scoring();
        return;
    }
    for(int i=length;i<N;i++){
        if(abuf[i] == 0){
            abuf[i] = 1;
            solve(length+1);
            abuf[i] = 0;    
        } else {
            return;
        }
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0;i<N;i++)
        for(int j=0;j<N;j++)
            cin >> score[i][j];
    abuf[0] = 1;

    solve(1);
    printf("%d",res);
}