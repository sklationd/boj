#include <iostream>
#include <string>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,i;
    cin >> T;
    for(i=0;i<T;i++){
        string s;
        cin >> s;
        bool condition = (s.length()==7);
        condition = condition && (s[0]==s[1] && s[1]==s[4]);
        condition = condition && (s[0]!=s[2]);
        condition = condition && (s[2]==s[3] && s[3]==s[5] && s[5]==s[6]);
        if(condition)
            cout << 1 << "\n";
        else
            cout << 0 << "\n";        
    }
}