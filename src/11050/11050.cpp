#include <iostream>

using namespace std;

int binomialCoefficients(int n, int k) {
   if (k == 0 || k == n)
   return 1;
   return binomialCoefficients(n - 1, k - 1) + binomialCoefficients(n - 1, k);
}

int main(){
    int N,K;
    cin >> N >> K;
    cout << binomialCoefficients(N,K);
}