#include <iostream>
#include <stack>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long int ll;

int main(){
    // for fast io 
    fastio;
    ll N,L,i;
	cin >> N >> L;

	stack<ll> S;
    for(i=0;i<N;i++){
		ll temp;
		cin >> temp;
		S.push(temp);
    }

	ll center = S.top();
	S.pop();
	ll count = 1;
	while(!S.empty()){
		if(center <= (S.top() - L)*count || center >= (S.top() + L)*count) {
			cout << "unstable";
			return 0;
		}
		center = S.top() + center;
		S.pop();
		count++;
	}
	cout << "stable";
	return 0;
}
