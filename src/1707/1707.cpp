#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<int> graph[20001];
int color[20001] = {0,};
bool checked[20001];

bool dfs(int v1, int input_color){
    int i;
    checked[v1] = true;
    color[v1] = input_color;
    for(i=0;i<graph[v1].size();i++){
        if (color[graph[v1][i]] == 0){ // not assigned yet
            if(!dfs(graph[v1][i],-input_color))
                return false;
        } else if (color[graph[v1][i]] == input_color)
            return false;
    }
    return true;
}

int main(){
    int N,V,E,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> V >> E;

        //initialize
        for(j=0;j<E;j++){
            int v1,v2;
            cin >> v1 >> v2;
            graph[v1].push_back(v2);
            graph[v2].push_back(v1);
        }
        bool result = true;
        memset(checked,false,sizeof(checked));

        for(j=1;j<=V;j++){
            if(checked[j])
                continue;
            result = result && dfs(j,1);
            memset(color, 0, sizeof(color));
        }

        if (result) cout << "YES" << "\n";
        else cout << "NO" << "\n";

        // clear variable
        for(j=0;j<=V;j++)
            graph[j].clear();
        memset(checked,false,sizeof(checked));
    }
}