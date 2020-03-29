#include <iostream>
#include <queue>

using namespace std;

int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    queue<int> q;
    for(i=0;i<N;i++){
        string command;
        cin >> command;
        if(!command.compare("push")){
            int X;
            cin >> X;
            q.push(X);
        } 
        else if (!command.compare("pop")) {
            if(q.empty())
                cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } 
        else if (!command.compare("size")) cout << q.size() << "\n";
        else if (!command.compare("empty")) cout << (q.empty()?1:0) << "\n";
        else if (!command.compare("front")) cout << (q.empty()?-1:q.front()) << "\n";
        else if (!command.compare("back")) cout << (q.empty()?-1:q.back()) << "\n";
        else {
            // not reached
            return 0;
        }
        
    }
}