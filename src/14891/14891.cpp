#include <iostream>
#include <deque>
#include <string>

using namespace std;

void rotate_gear(deque<int> &gear, int clockwise){
    if(clockwise == -1){
        int temp;
        temp = gear.front();
        gear.pop_front();
        gear.push_back(temp);
    } else if(clockwise == 1){
        int temp;
        temp = gear.back();
        gear.pop_back();
        gear.push_front(temp);
    }
}

void rotate_gearbox(deque<int> gearbox[4], int gear_num, int clockwise, int direction){
    if (direction <= 0) { // left
        if(gear_num >= 2){
            if(gearbox[gear_num-1][6] != gearbox[gear_num-2][2])
                rotate_gearbox(gearbox, gear_num-1, -clockwise, -1);
        } 
    }
    if (direction >= 0) { //right
                if (gear_num <= 3){ 
            if(gearbox[gear_num-1][2] != gearbox[gear_num][6])
                rotate_gearbox(gearbox, gear_num+1, -clockwise, 1);
        }
    }
    rotate_gear(gearbox[gear_num-1], clockwise);
}

int score(deque<int> gearbox[4]){
    int result = 0;
    for(int i=0;i<4;i++){
        result += gearbox[i][0] * (1<<i);
    }
    return result;
}

int main(){
    deque<int> gearbox[4];

    int i,j;
    for(i=0;i<4;i++){
        string s;
        cin >> s;
        for(j=0;j<8;j++){
            gearbox[i].push_back(s[j]-'0');
        }
    }

    int N;
    cin >> N;
    for(i=0;i<N;i++){
        int gear_num, clockwise;
        cin >> gear_num >> clockwise;
        rotate_gearbox(gearbox, gear_num, clockwise, 0);
    }

    cout << score(gearbox) << endl;
}