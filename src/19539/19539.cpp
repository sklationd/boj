#include <iostream>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    int count_2 = 0;
    int count_1 = 0;
    for(i=0;i<N;i++){
        int temp;
        cin >> temp;
        count_2 += (temp/2);
        count_1 += (temp%2);
    }
    int diff = count_2 - count_1;
    if(diff >= 0 && diff % 3 == 0)
        cout << "YES" << "\n";
    else 
        cout << "NO" << "\n";

}