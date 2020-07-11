#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int a[4];
    int i;
    cin >> a[0] >> a[1] >> a[2];
    sort(a,a+3);
    for(i=0;i<3;i++)
        cout << a[i] << " ";
}