#include <iostream>
#include <algorithm>
#include <assert.h>

#define MAX 1000000001

using namespace std;

int num[12]; 
int ops[4]; // number of operator
int N;
int maxV = -MAX;
int minV = MAX;

void DFS(int index, int plus, int minus, int mul, int div, int result){
    if(index == N){ // done
        if(result > maxV)
            maxV = result;
        if(minV > result)
            minV = result;
    } else {
        int val = num[index++];
        if(plus > 0)
            DFS(index, plus-1, minus, mul, div, result + val);
        if(minus > 0)
            DFS(index, plus, minus-1, mul, div, result - val);
        if(mul > 0)
            DFS(index, plus, minus, mul-1, div, result * val);
        if(div > 0)
            DFS(index, plus, minus, mul, div-1, result / val);
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int i;
    cin >> N;

    assert(N>0);

    for(i=0;i<N;i++) cin >> num[i];
    for(i=0;i<4;i++) cin >> ops[i];

    DFS(1, ops[0], ops[1], ops[2], ops[3], num[0]);

    printf("%d\n", maxV);
    printf("%d\n", minV);
}
