#include <iostream>
#include <stack>
#include <queue>
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    stack<int> s;
    queue<char> q;
    int N,i;
    cin >> N;
    int arr[100001] = {0,};
    for(i=0;i<N;i++)
        cin >> arr[i];
    int index = 0;
    for(i=1;i<=N;i++){
        if(arr[index]==i){
            q.push('+');
            q.push('-');
            index++;
        } else {
            q.push('+');
            s.push(i);
        }

        while(s.size() && s.top()==arr[index]){
            s.pop();
            q.push('-');
            index++;
        }
    }

    if(q.size()!=2*N)
        cout << "NO";
    else {
        while(q.size()){
            cout << q.front() << "\n";
            q.pop();
        }
    }


}