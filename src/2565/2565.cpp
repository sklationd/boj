#include <iostream>

int A[501] = {0,};
int updp[501] = {0,};

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        int index;
        cin >> index;
        cin >> A[index - 1];
    }
    
    for(i=0;i<500;i++){
        if(A[i] != 0){
            int max = 1;
            for(j=0;j<i;j++){
                if(A[j]!=0){
                    if(A[i]>A[j]){
                        if(max < updp[j] + 1)
                            max = updp[j] + 1;
                    }
                }
            }
            updp[i] = max;
        }
    }
    int max = 0;
    for(i=0;i<500;i++){
        if(updp[i] > max){
            max = updp[i];
        }
    }
    cout << N - max;
}