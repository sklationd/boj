#include <iostream>
using namespace std;

typedef unsigned long long int ll;

char buf[1 << 17];
char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17) {
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}
int readInt() {
	int t, r = read() & 15;
	while ((t = read()) & 16) r = r * 10 + (t & 15);
	return r;
}


ll power(ll a, ll n, ll p){
    ll result = 1;
    while(n>0){
        if(n%2 == 1)
            result = (result * a) % p;
        a = (a * a) % p;
        n/=2;
    }
    return result;
}


bool MR(ll a, ll n){
    ll k = n-1;
    while(k%2 == 0){
        if(power(a,k,n) == n-1)
            return true;
        k/=2;
    }
    ll t = power(a, k, n);
    return t == n-1 || t == 1;
}


bool PT(ll n, int size){
    if(n <= 1)
        return false;

    if(n < 10000ULL) {
        for (ll i = 2; i*i <= n; i++)
            if (n % i == 0)
                return false;
        return true;
    }

    ll list[3] = {2,7,61};
    for(int i=0;i<3;i++){
        if(!MR(list[i],n))
            return false;
    }
    return true;
}


int main(){
    ll N,i;
    N = readInt();
    int count = 0;
    for(i=0;i<N;i++){
        ll A;
        A = readInt();
        if(A < 4){
            count++;
            continue;
        }
        if(PT(2*A + 1, 32))
            count++;   
    }
    cout << count << "\n";
}