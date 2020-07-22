#include <iostream>

using namespace std;

int C(int N, int M){
    if(N==1) return M-1;
    if(M==1) return N-1;
    return C(N/2,M) + C(N/2+N%2,M) + 1;
}

int main(){
    int N,M,i;
    cin >> N >> M;
    cout << C(N,M) <<"\n";
}