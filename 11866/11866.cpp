#include <iostream>
#include <queue>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    queue<int> q1;
    queue<int> q2;    

    int N,K,i;
    cin >> N >> K;
    for(i=1;i<=N;i++) q1.push(i);
    int count = 1;
    while(!q1.empty()){
        if(count++ == K){
            count = 1;
            int temp = q1.front();
            q2.push(temp);
            q1.pop();
        } else {
            int temp = q1.front();
            q1.pop();
            q1.push(temp);
        }
    }
    // while(!q2.empty()){
    //     cout << q2.front();
    //     q2.pop();
    // }
    cout << "<";
    while(!q2.empty()){
        cout << q2.front();
        q2.pop();
        if(!q2.empty()) 
            cout << ", ";
    }
    cout << ">";
}