#include <iostream>
#include <cmath>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    long double S = (long double)sqrt(3)/4.0;
    S = S * N * N;
    printf("%.13Lf", S);
}