#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>

using namespace std;

int king_x, king_y, rock_x, rock_y, N;

bool move(int a, int b){
    if(a < 0 && king_x == 0)
        return false;
    if(a > 0 && king_x == 7)
        return false;
    if(b < 0 && king_y == 0)
        return false;
    if(b > 0 && king_y == 7)
        return false;
    if(king_x + a == rock_x && king_y + b == rock_y){
        if(a < 0 && rock_x == 0)
            return false;
        if(a > 0 && rock_x == 7)
            return false;
        if(b < 0 && rock_y == 0)
            return false;
        if(b > 0 && rock_y == 7)
            return false;
        rock_x += a;
        rock_y += b;
    }
    king_x += a;
    king_y += b;
    return true;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string king;
    string rock;

    cin >> king >> rock >> N;
    king_x = king[0] - 'A';
    king_y = king[1] - '1';
    rock_x = rock[0] - 'A';
    rock_y = rock[1] - '1';

    for(int i=0;i<N;i++){
        string comm;
        cin >> comm;
        if(!comm.compare("L")) move(-1,0);
        else if(!comm.compare("R")) move(1,0);
        else if(!comm.compare("B")) move(0,-1);
        else if(!comm.compare("T")) move(0,1);
        else if(!comm.compare("RT")) move(1,1);
        else if(!comm.compare("LT")) move(-1,1);
        else if(!comm.compare("RB")) move(1,-1);
        else move(-1,-1);
    }
    cout << (char)(king_x + 'A');
    cout << (char)(king_y + '1') << endl;
    cout << (char)(rock_x + 'A');
    cout << (char)(rock_y + '1') << endl;
       
}