#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}


int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    vector<int> list;
    vector<int> disparity;
    int N,i;
    cin >> N;
    
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    for(i=0;i<N-1;i++){
        disparity.push_back(abs(list[i] - list[i+1]));
    }

    int comp = disparity[0];
    for(i=1;i<N-1;i++){
        comp = gcd(comp, disparity[i]);
    }
    for(i=2;i<=comp/2+1;i++){
        if(comp%i==0)
            cout << i << " ";
    }
    cout << comp;
}