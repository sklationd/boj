#include <iostream>
#include <algorithm>

using namespace std;
int main(){
    int a,b,c;
    cin >> a >> b >> c;
    if(a==b && b==c) cout << 10000 + 1000*a << "\n";
    else if(a==b || b==c || a==c){
        int num;
        if(a==b || b==c) num = b;
        if(a==c) num = c;
        cout << 1000 + num*100 << "\n";
    } else {
        cout << max({a,b,c}) * 100 << "\n";
    }
    return 0;
}