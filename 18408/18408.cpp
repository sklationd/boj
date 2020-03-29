#include <iostream>

using namespace std;
int main(){
    int A[3];
    int i;
    int count = 0;
    cin >> A[0] >> A[1] >> A[2];
    for(i=0;i<3;i++){
        if(A[i] == 1)
            count++;
    }
    if(count > 1)
        cout << 1;
    else
        cout << 2;
}