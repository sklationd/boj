#include <iostream>

using namespace std;

int max(int a, int b){
    if(a>b) return a;
    else return b;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n,h,v;
    cin >> n >> h >> v;
    cout << 4*(max(n-h,h)*max(n-v,v));
}