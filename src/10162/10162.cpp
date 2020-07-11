#include <iostream>
#include <assert.h>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    
    if(N%10)
        printf("-1");
    else {
        int r = N;
        int A = r/300;
        r %= 300;

        int B = r/60;
        r %= 60;

        int C = r/10;
        r %= 10;

        assert(r==0);

        printf("%d %d %d",A,B,C);
    }
}