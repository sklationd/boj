#include <iostream>
#include <vector>
#include <algorithm>
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
	int n,i;
	n = readNInt();
    vector<int> V;
	for(i=0;i<n;i++){
        V.push_back(readNInt());
	}
	sort(V.begin(), V.end());
	for(i=0;i<n;i++){
		printf("%d\n",V[i]);
	}
}


