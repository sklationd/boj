#include <iostream>
#define PI 3.14159265358979

using namespace std;

int main(){
    int A_1, P_1, R_1, P_2;
    cin >> A_1 >> P_1 >> R_1 >> P_2;
    double A_2 = R_1*R_1*PI;
    double r1,r2;
    r1 = (double)A_1/P_1;
    r2 = A_2/P_2;
    if(r1 > r2){
        cout << "Slice of pizza\n";
    } else {
        cout << "Whole pizza\n";
    }
}