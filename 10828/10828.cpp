#include <iostream>
#include <stack>
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        string command;
        cin >> command;
        if(!command.compare("push")){
            int X;
            cin >> X;
            s.push(X);
        } 
        else if (!command.compare("pop")) {
            if(s.empty())
                cout << -1 << "\n";
            else {
                cout << s.top() << "\n";
                s.pop();
            }
        } 
        else if (!command.compare("size")) cout << s.size() << "\n";
        else if (!command.compare("empty")) cout << (s.empty()?1:0) << "\n";
        else if (!command.compare("top")) cout << (s.empty()?-1:s.top()) << "\n";
        else {
            // not reached
            return 0;
        }
    }
}