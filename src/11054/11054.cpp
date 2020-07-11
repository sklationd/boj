#include <iostream>

int array[1001] = {0,};
int lowdp[1001] = {0,};
int updp[1001] = {0,};

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> array[i];
    }

    updp[0] = 1;
    for(i=1;i<N;i++){
        int max = 1;
        for(j=0;j<i;j++){
            if(array[i]>array[j]){
                if(max < updp[j] + 1)
                    max = updp[j] + 1;
            }
        }
        updp[i] = max;
    }

    lowdp[N-1] = 1;
    for(i=N-2;i>=0;i--){
        int max = 1;
        for(j=N-1;j>i;j--){
            if(array[j]<array[i]){
                if(lowdp[j] + 1 > max)
                    max = lowdp[j] + 1;
            }
        }
        lowdp[i] = max;
    }

    int result = 0;
    for(i=0;i<N;i++){
        if(result < (lowdp[i] + updp[i] - 1)){
            result = lowdp[i] + updp[i] - 1;
        }
    }
    printf("%d",result);

}