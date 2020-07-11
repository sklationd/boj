#include <iostream>
#include <queue>
#define MAX 100001
#define HALFMAX 50000
using namespace std;


int map[MAX] = {0,};
queue<int> q;

int main(){
    int X,Y;
    cin >> X >> Y;

    if(X==Y){
        cout << 0;
        return 0;
    }

    q.push(X);
    int step = 0;
    while(!q.empty()){
        int temp = q.front();
        q.pop();

        if(temp >= 1){
            if(!map[temp-1]){
                map[temp-1] = map[temp]+1;
                q.push(temp-1);
            }
        }
        if(temp <= MAX-1){
            if(!map[temp+1]){
                map[temp+1] = map[temp]+1;
                q.push(temp+1);
            }
        }
        if(temp <= HALFMAX){
            if(!map[temp*2]){
                map[temp*2] = map[temp]+1;
                q.push(temp*2);
            }
        }

        // if done, return
        if(temp-1 == Y || temp+1 == Y || 2*temp == Y)
            break;

    }
    cout << map[Y];
}