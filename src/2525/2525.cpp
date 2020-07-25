#include <iostream>

using namespace std;
 
int main(){
    int H,M,D;
    cin >> H >> M >> D;
    M += D;
    H += M / 60;
    M %= 60;
    H %= 24;
    cout << H << " " << M << "\n";
}