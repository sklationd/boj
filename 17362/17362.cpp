#include <iostream>

using namespace std;

int result[9] = {2,1,2,3,4,5,4,3,2};
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    cout << result[N%8];
}