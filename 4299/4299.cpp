#include <iostream>
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a,b;
    cin >> a >> b;
    
    if(a<b) {
        cout << -1;
        return 0;
    }
    if((a-b)%2 == 0){
        b=(a-b)/2;
        a = a-b;
        cout << a << " " << b;
    } else {
        cout << -1;
    }
}