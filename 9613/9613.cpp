#include <iostream>

using namespace std;

int buf[101];

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
    int N,M,X,Y,i,j;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> M;
        for(j=0;j<M;j++)
            cin >> buf[j];
        if(M==1){
            cout << buf[0];
            continue;
        }
        long long sum=0;
        int a=0;
        int b=1;
        while(a<M-1){
            while(b<M){
                sum+=gcd(buf[a],buf[b]);
                b++;
            }
            a++;
            b=a+1;
        }
        cout << sum << "\n";
    }
}