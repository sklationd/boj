#include <iostream>
int cards[20000001] = {0,};

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        cards[temp+10000000] +=1;
    }
    int M;
    cin >> M;
    for(i=0;i<M;i++){
        int temp;
        cin >> temp;
        cout << cards[temp + 10000000] << " ";
    }
}