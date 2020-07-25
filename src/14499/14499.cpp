#include <iostream>

using namespace std;

int N,M;
int map[21][21] = {0,};

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

class Dice{
    public:
        // 1,2,3,4,5,6
        int val[6] = {0,0,0,0,0,0};
        int x,y;

    Dice(int x_, int y_){
        x = x_;
        y = y_;
    }

    void upper_face(){
        cout << val[0] << "\n";
    }

    void copy() {
        if(map[x][y]==0){
            map[x][y] = val[5];
        } else {
            val[5] = map[x][y];
            map[x][y] = 0;
        }
        upper_face();
    }

    void east() {
        if(y+1<=M-1){
            swap(&val[0],&val[4]);
            swap(&val[1],&val[5]);
            swap(&val[0],&val[5]);
            y++;
            copy();
        }
    }

    void west() {
        if(y-1>=0){
            swap(&val[0],&val[1]);
            swap(&val[4],&val[5]);
            swap(&val[0],&val[5]);
            y--;
            copy();
        }
    }

    void south() {
        if(x+1<=N-1){
            swap(&val[0],&val[2]);
            swap(&val[3],&val[5]);
            swap(&val[0],&val[5]);
            x++;
            copy();
        }

    }

    void north() {
        if(x-1>=0){
            swap(&val[0],&val[2]);
            swap(&val[3],&val[5]);
            swap(&val[2],&val[3]);
            x--;
            copy();
        }
    }
};  

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x,y,K,i,j;

    cin >> N >> M >> x >> y >> K;

    Dice dice = Dice(x,y);

    for(i=0;i<N;i++){
        for(j=0;j<M;j++){
            cin >> map[i][j];
        }
    }

    for(i=0;i<K;i++){
        int command;
        cin >> command;
        switch (command) {
            case 1:
                dice.east();
                break;
            case 2:
                dice.west();
                break;
            case 3:
                dice.north();
                break;
            case 4:
                dice.south();
                break;
        }
    }
}