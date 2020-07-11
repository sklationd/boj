#include <iostream>
#include <vector>

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

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        list.push_back(temp);
    }
    int u = 1;
    int d = 1;
    
    for(i=0;i<N-1;i++){
        u = u*list[i];
        d = d*list[i+1];
        int gcdn = gcd(u,d);
        u = u/=gcdn;
        d = d/=gcdn;
        cout << u << "/" << d << endl;
    }
}