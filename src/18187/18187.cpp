#include <iostream>
using namespace std;

int an(int n){
    int k = n/3;
    if(n%3 == 1){
        return 3*k*k + 5*k + 2;
    } else if(n%3 == 2){
        return 3*k*k + 7*k + 4;
    } else {
        return 3*k*k + 3*k + 1;
    }
}

int main(){
    int N;
    cin >> N;
    cout << an(N) << "\n";
}