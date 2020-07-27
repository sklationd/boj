#include <iostream>
#include <vector>
#include <queue>
using namespace std;

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

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,i,j;
    N=readInt();

    // time
    vector<int> time(N+1,-1);
    // network
    vector<vector<int>> net(N+1);
    // number of timeiever in neighborhood
    vector<int> nb(N+1,0);
    // BFS Q
    queue<int> Q;

    for(i=1;i<=N;i++){
        while(1){
            int neighbor;
            neighbor = readInt();
            if(neighbor == 0) break;
            net[i].push_back(neighbor);
        }
    }

    int t = 0;

    M = readInt();
    for(i=0;i<M;i++){
        int temp;
        temp = readInt();
        time[temp] = t;
        Q.push(temp);
    }

    // number of timeiever in neighborhood of N

    while(!Q.empty()){
        t++;
        
        // if new count is 0, terminate.
        int s = Q.size();
        for(i=0;i<s;i++){
            int host = Q.front();Q.pop();
            for(j=0;j<net[host].size();j++){
                int nbh = net[host][j];
                if(time[nbh]==-1){
                    nb[nbh]++;
                    if(nb[nbh]*2 >= net[nbh].size()){
                        Q.push(nbh);
                        time[nbh] = t;
                    }
                }
            }
        }
    }

    for(i=1;i<=N;i++){
        cout << time[i] << " ";
    }
}