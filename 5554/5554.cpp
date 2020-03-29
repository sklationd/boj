#include <iostream>

using namespace std;
int main(){
    int i;
    int sum = 0;
    for(i=0;i<4;i++){
        int temp;
        cin >> temp;
        sum += temp;
    }
    cout << sum/60 << endl;
    cout << sum%60 << endl;
}