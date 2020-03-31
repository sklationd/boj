#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int X,L,R;
    cin >> X >> L >> R;
    
    if(L==R) cout << L ;
    else if(L > X) cout << L;
    else if(L<=X && X<=R) cout << X;
    else cout << R;
}