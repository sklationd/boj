#include <iostream>
#include <math.h>
using namespace std;
int main(){
    int ax,ay,az,cx,cy,cz;
    cin >> ax >> ay >> az >> cx >> cy >> cz;
    cout << cx-az << " " << cy/ay << " " << cz - ax;
}