#include <iostream>

using namespace std;

int gcd(int a, int b){
	while(b!=0){
		int r = a%b;
		a= b;
		b= r;
	}
	return a;
}

int lcm(int a, int b){
    return a * b / gcd(a,b);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int N,X,Y,i;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> X >> Y;
        cout << lcm(X,Y) << "\n";
    }
}