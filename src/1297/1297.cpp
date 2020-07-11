#include <iostream>
#include <math.h>
using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    double I,H,W,R;
    cin >> I >> H >> W;
    R = sqrt(I*I / (H*H + W*W));
    double aH, aW;
    aH = R*H;
    aW = R*W;
    cout << floor(aH) << " " << floor(aW);
}