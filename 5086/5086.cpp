#include <iostream>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        int a,b;
        cin >> a;
        cin >> b;
        if(a==0 && b==0)
            break;
        else{
            if(b%a==0)
                cout << "factor" << endl;
            else if(a%b==0)
                cout << "multiple" << endl;
            else
                cout << "neither" << endl;
        }
    }
}