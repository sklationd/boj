#include <iostream>
using namespace std;

int main(){
    int A,B,C;
    cin >> A >> B >> C;
    int count = 0;
    int i=0;
    while(count < C){
        if(++i%7 == 0){
            count += A+B;
        } else {
            count += A;
        }
    }
    cout << i << "\n";
}