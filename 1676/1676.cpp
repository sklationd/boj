#include <iostream>

using namespace std;

int min2(int a, int b){
    return a>b?b:a;
}


int zeros(int n){
    int two = 0, five = 0, i = 0;
    for (i = 2; i <= n; i *= 2) two += n / i;
    for (i = 5; i <= n; i *= 5) five += n / i;
    return min2(two, five);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    cout << zeros(N);
}