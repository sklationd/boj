#include <iostream>
#include <queue>
#include <cmath>
#include <tuple>
#define MAX_INT 2147483647
using namespace std;

int map[21][21];
int N,r,c;
int shark = 2;
int eat_count = 0;

tuple<int, int, int> fish_find(int r, int c){
    int d = 0;

    int min_r, min_c, min_d;
    min_r = -1;
    min_c = -1;
    min_d = MAX_INT;

    queue<tuple<int, int, int>> Q;
    Q.push(make_tuple(r,c,0));
    
    int mark[21][21] = {0,};
    mark[r][c] = 1;

    while(!Q.empty()){
        int len = Q.size();
        for(int i=0;i<len;i++){
            tuple<int, int, int> T = Q.front();
            Q.pop();

            int curr_r = get<0>(T);
            int curr_c = get<1>(T);
            int curr_d = get<2>(T);
            
            bool eat = false;
            
            // can eat?
            if((curr_r!=r || curr_c!=c) && map[curr_r][curr_c] > 0){ 
                bool cond = (map[curr_r][curr_c] < shark);
                if(cond){
                    if(min_d == curr_d){
                        if(curr_r < min_r){
                            min_r = curr_r;
                            min_c = curr_c;
                            min_d = curr_d;
                            eat = true;
                        } else if(curr_r == min_r) {
                            if(curr_c < min_c){
                                min_r = curr_r;
                                min_c = curr_c;
                                min_d = curr_d;
                                eat = true;
                            }
                        }
                    } else if(curr_d < min_d){
                        min_r = curr_r;
                        min_c = curr_c;
                        min_d = curr_d;
                        eat = true;
                    }
                }
            }
            
            if(!eat){
                // upper
                if(curr_r > 0){
                    bool cond = (mark[curr_r-1][curr_c]==0);
                    cond = cond && (map[curr_r-1][curr_c] <= shark);
                    cond = cond && (curr_d + 1 <= min_d);
                    if(cond){
                        Q.push(make_tuple(curr_r-1, curr_c, curr_d + 1));
                        mark[curr_r-1][curr_c]=1;
                    }
                }   
                // below
                if(curr_r < N-1){
                    bool cond = (mark[curr_r+1][curr_c]==0);
                    cond = cond && (map[curr_r+1][curr_c] <= shark);
                    cond = cond && (curr_d + 1 <= min_d);
                    if(cond){
                        Q.push(make_tuple(curr_r+1, curr_c, curr_d + 1));
                        mark[curr_r+1][curr_c]=1;
                    }
                }
                // left
                if(curr_c > 0){
                    bool cond = (mark[curr_r][curr_c-1]==0);
                    cond = cond && (map[curr_r][curr_c-1] <= shark);
                    cond = cond && (curr_d + 1 <= min_d);
                    if(cond){
                        Q.push(make_tuple(curr_r, curr_c-1, curr_d + 1));
                        mark[curr_r][curr_c-1]=1;
                    }
                }
                // right
                if(curr_c < N-1){
                    bool cond = (mark[curr_r][curr_c+1]==0);
                    cond = cond && (map[curr_r][curr_c+1] <= shark);
                    cond = cond && (curr_d + 1 <= min_d);
                    if(cond){
                        Q.push(make_tuple(curr_r, curr_c+1, curr_d + 1));
                        mark[curr_r][curr_c+1]=1;
                    }
                }
            }
        }
    }
    
    return make_tuple(min_r, min_c, min_d);
}

// if shark can eat fish, than eat and return the number of movement
// else return 0; done
int eat(){
    // r, c, d
    tuple<int ,int, int> target_fish;
    target_fish = fish_find(r,c);
    int d = get<2>(target_fish);
    // not exist
    if(d==MAX_INT)
        return 0;

    // if exists
    if(d != 0){
        // move to target fish
        r = get<0>(target_fish);
        c = get<1>(target_fish);

        // eat the fish
        map[r][c] = 0;
        eat_count ++;
        if(eat_count == shark){
            shark++;
            eat_count = 0;
        }
    }

    return d;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int i,j;
    cin >> N;

    for(i=0;i<N;i++) {
        for(j=0;j<N;j++) {
            cin >> map[i][j];

            // Shark!
            if(map[i][j]==9){
                r = i;
                c = j;
                map[i][j] = 0;
            }
        }
    }

    int count = 0;
    while(1){
        int move = eat();
        if(move)
            count += move;
        else
            break;
    }

    cout << count << "\n";
}