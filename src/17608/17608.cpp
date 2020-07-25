#include <iostream>
#include <vector>
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    vector<int> histogram(N);
    for(i=0;i<N;i++){
        cin >> histogram[i];
    }
    
    int count = 0;
    int max_h = 0;
    for(i=N-1;i>=0;i--){
        if(histogram[i]>max_h){
            count++;
            max_h = histogram[i];
        }
    }

    cout << count << "\n";
}