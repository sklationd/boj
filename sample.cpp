#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

typedef long long int ll;

char buf[1 << 17];
inline char read() {
	static int idx = 1 << 17;
	if (idx == 1 << 17)
	{
		fread(buf, 1, 1 << 17, stdin);
		idx = 0;
	}
	return buf[idx++];
}

// Positive
inline int readPInt() {
    int t, r = read() & 15;
    while ((t = read()) & 16) r = r * 10 + (t & 15);
    return r;
}

// Negative
inline int readNInt() {
	int sum = 0;
	bool flg = 1;
	char now = read();
	while (now == 10 || now == 32) now = read();
	if (now == '-') flg = 0, now = read();
	while (now >= 48 && now <= 57)
	{
		sum = sum * 10 + now - 48;
		now = read();
	}

	return flg ? sum : -sum;
}

int main(){
    // for fast io 
    fastio;

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        
    }
	return 0;
}
