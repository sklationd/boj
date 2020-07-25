#include <iostream>
using namespace std;

int main(){
    int T,N,M,i;
    cin >> T;
    for(i=0;i<T;i++){
        cin >> N >> M;
        if(N<=11 || M<=3) cout << -1 << "\n";
        else cout << M*11 + 4 << "\n";
    }
    return 0;
}