#include <iostream>
#include <string>
#include <map>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,i;
    cin >> N >> M;

    map<string, string> m;
    
    for(i=0;i<N;i++){
        string web, passwd;
        cin >> web >> passwd;
        m[web]=passwd;
    }

    for(i=0;i<M;i++){
        string web;
        cin >> web;
        cout << m[web] << "\n";
    }

    return 0;
}