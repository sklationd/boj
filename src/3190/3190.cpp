#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int N, K, L;
int len = 1;
int t = 1;

// Position of each part of snake
deque<pair<int, int>> snake;

// 0: right, 1: down, 2: left, 3: up
int direction = 0;

// 0 : nothing, 1 : apple
int map[101][101] = {0,};

bool check(int r, int c){
    if(0<=r && r<N && 0<=c && c<N){
        for(int i=0;i<len;i++){
            if(snake[i].first == r && snake[i].second == c){
                return false;
            }
        }
        return true;
    }
    return false;
}

void forward(int r, int c){
    if(map[r][c]==0){
        snake.push_front(make_pair(r,c));
        snake.pop_back();
    } else { // apple
        snake.push_front(make_pair(r,c));
        map[r][c]=0;
        len++;
    }
}

bool step(){
    int snake_r = snake[0].first;
    int snake_c = snake[0].second;

    switch(direction){
        case 0: // right
            if(check(snake_r, snake_c+1)){
                forward(snake_r, snake_c+1);
                return true;
            }
            break;
        case 1: // down
            if(check(snake_r+1, snake_c)){
                forward(snake_r+1, snake_c);
                return true;
            }
            break;
        case 2: // left
            if(check(snake_r, snake_c-1)){
                forward(snake_r, snake_c-1);
                return true;
            }
            break;
        case 3: // up
            if(check(snake_r-1, snake_c)){
                forward(snake_r-1, snake_c);
                return true;
            }
            break;
    }
    return false;
}

void start(vector<pair<int, bool>> &Op){
    for(int i=0;i<Op.size();i++){
        int turn_time = Op[i].first;
        while(t <= turn_time){
            if(step()){
                t++;
            } else {
                return;
            }
        }
        if(Op[i].second){ // right
            direction = (direction + 1) % 4;
        } else {
            direction = (direction + 3) % 4;
        }
    }
    while(step())
        t++;
}


int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    snake.push_front(make_pair(0,0));

    cin >> N >> K;
    for(int i=0;i<K;i++){
        int x, y;
        cin >> x >> y;
        map[x-1][y-1] = 1;
    }

    cin >> L;
    vector<pair<int, bool>> Op(L);
    for(int i=0;i<L;i++){
        cin >> Op[i].first;
        char op;
        cin >> op;
        if(op == 'L')
            Op[i].second = false;
        else 
            Op[i].second = true;
    }
    start(Op);
    cout << t << "\n";
}