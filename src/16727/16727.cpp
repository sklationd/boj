#include <iostream>
using namespace std;

int main(){
    int A_1, B_1, A_2, B_2;
    cin >> A_1 >> B_1 >> B_2 >> A_2 ;
    int A,B;
    A = A_1 + A_2;
    B = B_1 + B_2;
    if(A>B){
        cout << "Persepolis" << "\n";
    } else if(B<A){
        cout << "Esteghlal" << "\n";
    } else {
        if(A_2 > B_1){
            cout << "Persepolis" << "\n";
        } else if(A_2 < B_1){
            cout << "Esteghlal" << "\n";
        } else {
            cout << "Penalty" << "\n";
        }
    }
}