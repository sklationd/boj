#include <iostream>
#include <stack>
using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        stack<char> s;
        string str;
        bool result = true;
        cin >> str;
        for(j=0;j<str.size();j++){
            if(str[j]=='(') s.push(str[j]);
            else if(str[j]==')'){
                if(s.empty()) {
                    result = false;
                    break;
                }
                if(s.top()=='(') s.pop();
                else {
                    result = false;
                    break;
                }
            } else {
                continue;
            }
        }
        if(!s.empty()) result = false;
        if(result) cout << "YES\n";
        else cout << "NO\n";
    }
}