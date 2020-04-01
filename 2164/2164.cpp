#include <iostream>
#include <queue>


using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q;
    int N,i;
    cin >> N;
    for(i=1;i<=N;i++) q.push(i);
    while(q.size()>1) {
        q.pop();
        q.push(q.front());
        q.pop();
    }
    cout << q.front();
}