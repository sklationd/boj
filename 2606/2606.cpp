#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v[101];
    queue<int> q;
    int check[101] = {0,};
    int C,N,i;
    cin >> C >> N;
    for(i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        v[a-1].push_back(b);
        v[b-1].push_back(a);
    }
    for(i=0;i<v[0].size();i++) {
        q.push(v[0][i]);
        check[v[0][i]-1] = 1;
    }
    while(!q.empty()){
        int temp = q.front();
        q.pop();
        for(i=0;i<v[temp-1].size();i++){
            if(!check[v[temp-1][i]-1]){
                q.push(v[temp-1][i]);
                check[v[temp-1][i]-1] = 1;
            }
        }
    }
    int result = 0;
    for(i=0;i<C;i++){
        if(check[i]!=0) result++;
    }
    cout << result - 1;
}