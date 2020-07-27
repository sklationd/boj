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

    // believer
    vector<int> bel(N+1,-1);
    // network
    vector<vector<pair<int,bool>>> net(N+1);
    // infector
    queue<int> infect;

    for(i=1;i<=N;i++){
        while(1){
            int neighbor;
            neighbor = readInt();
            if(neighbor == 0) break;
            net[i].push_back(make_pair(neighbor,false));
        }
    }

    int t = 0;

    M = readInt();
    for(i=0;i<M;i++){
        int temp;
        temp = readInt();
        bel[temp] = t;
        infect.push(temp);
    }

    // number of believer in neighborhood of N
    vector<int> nb(N+1,0);

    while(1){
        t++;
        
        // if new count is 0, terminate.
        int new_count = 0;
        int s = infect.size();
        for(i=0;i<s;i++){
            int host = infect.front();
            infect.pop();
            int count = 0;

            for(j=0;j<net[host].size();j++){
                int candidate = net[host][j].first;
                if(bel[candidate]==-1 && !net[host][j].second){
                    nb[candidate]++;
                    net[host][j].second = true;
                    if(nb[candidate]>=(net[candidate].size()+1)/2){
                        infect.push(candidate);
                        new_count++;
                        count++;
                        bel[candidate] = t;
                    }
                } else {
                    count++;
                }
            }
            
            if(count < net[host].size()){
                infect.push(host);
            }
        }

        if(new_count == 0)
            break;
    }

    for(i=1;i<=N;i++){
        cout << bel[i] << " ";
    }
}