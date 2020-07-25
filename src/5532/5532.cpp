#include <iostream>

using namespace std;

int max(int a, int b){
    return a>b?a:b;
}

int main(){
    int L,A,B,C,D;
    cin >> L >> A >> B >> C >> D;
    int K = A/C + (A%C?1:0);
    int M = B/D + (B%D?1:0);
    cout << L - max(K,M) << "\n";
}