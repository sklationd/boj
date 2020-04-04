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
        int input;
        cin >> input;
        if(input)
            s.push(input);
        else
            s.pop();
    }
    int sum = 0;
    while(!s.empty()){
        int temp = s.top();
        sum+=temp;
        s.pop();
    }
    cout << sum;
}