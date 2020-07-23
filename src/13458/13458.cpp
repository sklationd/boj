#include <iostream>
#include <vector>

using namespace std;

typedef long long int ll;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,B,C,i;
    cin >> N;
    vector<int> Ai(N,0);
    
    for(i=0;i<N;i++){
        cin >> Ai[i];
    }

    cin >> B >> C;
    ll count = N;
    for(i=0;i<N;i++){
        Ai[i] -= B;
        if(Ai[i] > B)
            count += (Ai[i]-1)/C + 1;
    }

    cout << count << "\n";

    return 0;
}