#include <iostream>
#include <algorithm>
using namespace std;

int a[100001] = {0,};

int bi(int start, int end, int number){
    int mid = (start+end)/2;
    if(mid == end)
        return (number == a[mid]);
    if(number > a[mid]){
        return bi(mid+1,end,number);
    } else {
        return bi(start, mid, number);
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,i;
    cin >> N;
    for(i=0;i<N;i++) 
        cin >> a[i];
    sort(a+0,a+N);
    cin >> M;
    for(i=0;i<M;i++){
        int temp;
        cin >> temp;
        cout << bi(0,N-1,temp) << "\n";
    }
}