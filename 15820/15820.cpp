#include <iostream>

using namespace std;
int main(){
    int S1,S2,i;
    cin >> S1 >> S2;
    int result = 1;
    for(i=0;i<S1;i++){
        long long int ans1, ans2;
        cin >> ans1 >> ans2;
        if(ans1 != ans2){
            cout << "Wrong Answer";
            return 0; 
        }
    }
    for(i=0;i<S2;i++){
        long long int ans1, ans2;
        cin >> ans1 >> ans2;
        if(ans1 != ans2){
            cout << "Why Wrong!!!";
            return 0;
        }
    }
    cout << "Accepted";
}