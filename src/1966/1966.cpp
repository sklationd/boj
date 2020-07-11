#include <iostream>
#include <queue>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    for(int i=0;i<N;i++){
        int M,K;
        cin >> M >> K;
        int max=0;
        
        queue<int> q;
        int priority_count[10] = {0,};
        int priority[101] = {0,};

        // Queue initialize and set maximum priority
        for(int j=0;j<M;j++){
            int temp;
            cin >> temp;
            if(max < temp)
                max = temp;
            priority_count[temp]++;
            priority[j]=temp;
            q.push(j);
        }
        
        // Logic
        int count = 0;
        while(q.size()){
            int candidate = q.front();
            if(max > priority[candidate]){
                q.pop();
                q.push(candidate);
            } else if(candidate == K){
                cout << count+1 << endl;
                break;
            } else {
                count++;
                q.pop();
                priority_count[priority[candidate]]--;
                if(priority_count[priority[candidate]]==0){
                    int index = priority[candidate];
                    while(!priority_count[--index]);
                    max = index;
                }
            }
        }
    }
}