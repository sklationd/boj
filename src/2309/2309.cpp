#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    vector<int> v;

    int i,j,k;
    for(i=0;i<9;i++){
        short h;
        cin >> h;
        v.push_back(h);
    }

    sort(v.begin(),v.end());

    for(i=0;i<9;i++){
        for(j=i+1;j<9;j++){
            int sum = 0;
            for(k=0;k<9;k++)
                if(k!=i && k!=j) sum+=v[k];
            if (sum==100){
                for(k=0;k<9;k++)
                    if(k!=i && k!=j) printf("%d\n",v[k]);
                return 0;
            }
                
        }
    }
}