#include <iostream>
#include <string>
using namespace std;

int FA(string &s){  
    int f = s[0]-'0';
    int l = s.length();
    return f*l;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string S;
    cin >> S;

    for(int i=0;i<10;i++){
        int r = FA(S);
        S = to_string(r);
    }
    if(S == to_string(FA(S)))
        cout << "FA" << "\n";
    else
        cout << "NFA" << "\n";    

}