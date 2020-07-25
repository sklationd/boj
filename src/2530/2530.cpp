#include <iostream>

using namespace std;
 
int main(){
    int H,M,S,D;
    cin >> H >> M >> S >> D;

    S += D;
    M += S / 60;
    S %= 60;

    H += M / 60;
    M %= 60;
    H %= 24;

    cout << H << " " << M << " " << S << "\n";
}