#include <iostream>

using namespace std;

int main(){
    int a,b,c,d,e,f;
    int x, y;
    cin >> a >> b >> c >> d >> e >> f;
    x = (e*c - b*f) / (a*e - b*d); 
    y = (c*d - a*f) / (b*d - a*e);
    cout << x << " " << y << "\n";
}