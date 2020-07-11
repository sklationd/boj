#include <iostream>

using namespace std;
int main(){
    int N;
    cin >> N;
    if(N%5){
        cout << N/5+1;
    } else {
        cout << N/5;
    }

}