#include <iostream>
#include <vector>
#define MAX 9
using namespace std;


int N,M;
int arr[MAX];
bool visited[MAX];

void bt(int count){
    if(count == M){
        int i;
        for(i=0;i<M;i++)
            cout << arr[i] << " ";
        cout << "\n";
    } else {
        int i;
        for(i=0;i<N;i++){
            arr[count] = i+1;
            bt(count+1);
        }
    }
}

int main(){
    cin>>N>>M;
    bt(0);
}