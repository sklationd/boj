#include <iostream>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int main(){
    // for fast io 
    fastio;

    int N,i;
    cin >> N;
	int A[101] = {0,};
    for(i=0;i<N;i++){
        int temp;
		cin >> temp;
		A[temp]++;
    }
	bool duplicate = false;
	int index = 0;
	int M = -1;
	for(i=1;i<=N;i++){
		if(M < A[i]){
			M = A[i];
			index = i;
			duplicate = false;
		} else if (M == A[i]){
			duplicate = true;
		} 
	}
	if(duplicate){
		cout << "skipped";
	} else {
		cout << index;
	}
	return 0;
}
