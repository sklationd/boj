#include <iostream>

using namespace std;

int min2(int a, int b){
    return a>b?b:a;
}

pair<long long, long long> zeros(long long n){
    long long two = 0, five = 0, i = 0;
    for (i = 2; i <= n; i *= 2) two += n / i;
    for (i = 5; i <= n; i *= 5) five += n / i;
    return (pair <long long, long long> (two, five));
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    long long N,M;
    cin >> N >> M;
    pair<long long, long long> ansN, ansNM, ansM;
    ansN = zeros(N);
    ansNM = zeros(N-M);
    ansM = zeros(M);
    
    long long c2 = ansN.first - ansNM.first - ansM.first;
    long long c5 = ansN.second - ansNM.second - ansM.second;

    cout << min2(c2, c5);
}

