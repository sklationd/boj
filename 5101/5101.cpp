#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int a0,d,an;
        cin >> a0 >> d >> an;
        if(d==0 && a0 == 0 && an==0) break;
        else if((an-a0)%d || (an-a0)*d < 0) cout << "X\n"; 
        else cout << ((an-a0) / d) + 1 << "\n";
    }
}
