#include <iostream>
using namespace std;

int main(){
    int A, B, C, A_, B_, C_;
    cin >> A >> B >> C >> A_ >> B_ >> C_;
    int team_1 = 3*A + 2*B + C;
    int team_2 = 3*A_ + 2*B_ + C_;
    if(team_1 > team_2)
        cout << "A" << "\n";
    else if(team_1 < team_2)
        cout << "B" << "\n";
    else
        cout << "T" << "\n";    
}