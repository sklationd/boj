#include <iostream>
#include <iomanip>
#define C 299792458
using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cout << setprecision(16);
    long double X,Y,Z;
    cin >> X >> Y;
    Z = (X + Y) / (1+(X/C)*(Y/C));
    cout << Z;
}