#include <iostream>
#include <string>
#include <cmath>
#define M 1234567891
using namespace std;

typedef unsigned long long int ll;

ll power(int n, int N){
    ll result = 1;
    for(int i=0;i<N;i++){
        result *= n;
        result %= M;
    }
    return result;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; 

    string input;
    cin >> input;
    ll result = 0;

    for(int i=0;i<N;i++){
        result += (input[i] - 'a' + 1) * power(31, i); 
        result %= M;
    }
    cout << result ;
}