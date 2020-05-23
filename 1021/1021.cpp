#include <iostream>
#include <deque>
using namespace std;

int N,K;
deque<int> dq;

void indexdown(int* index, int i){
    for(int j=i+1;j<K;j++){
        index[j]--;
        if(index[j]<1)
            index[j]=dq.size();
    }
}

void indexup(int* index, int i){
    for(int j=i+1;j<K;j++){
        index[j]++;
        if(index[j]>dq.size())
            index[j]%=dq.size();
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> K;

    int index[51] = {0,};
    for(int i=0;i<K;i++){
        cin >> index[i];
    }

    for(int i=0;i<N;i++){
        dq.push_back(i+1);
    }

    int count = 0;
    for(int i=0;i<K;i++){
        if(index[i] > (dq.size()+1)/2){
            int offset = dq.size() - index[i];
            for(int j=0;j<=offset;j++){
                count++;
                int temp = dq.back();
                dq.pop_back();
                dq.push_front(temp);
                indexup(index,i);
            }
            dq.pop_front();
            indexdown(index,i);
        } else {
            int offset = index[i] - 1;
            for(int j=0;j<offset;j++){
                count++;
                int temp = dq.front();
                dq.pop_front();
                dq.push_back(temp);
                indexdown(index,i);
            }
            dq.pop_front();
            indexdown(index,i);
        }
    }
    cout << count;
}