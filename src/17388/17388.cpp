#include <iostream>

using namespace std;

void min(int a, int b ,int c){
    if(a>b){
        if(b>c) cout << "Hanyang";
        else cout << "Korea";
    } else {
        if(a>c) cout << "Hanyang";
        else cout << "Soongsil";
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int S,K,H;
    cin >> S >> K >> H;
    if((S+K+H)<100) min(S,K,H);
    else cout << "OK";
}