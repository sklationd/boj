#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b,c,d;
    cin >> a >> b >> c >> d;
    if(a<8 || d<8 || b!=c) cout << "answer";
    else cout << "ignore";
}