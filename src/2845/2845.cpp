#include <iostream>

using namespace std;
int main(){
    int L,P,i;
    cin >> L >> P;
    for(i=0;i<5;i++){
        int temp;
        cin >> temp;
        cout << temp - L*P << ' ';
    }
}