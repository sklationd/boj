#include <iostream>

using namespace std;

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int score[50] = {0,};

    int i;
    for(i=0;i<50;i++){
        cin >> score[i];
    }

    int key_score;
    cin >> key_score;
    for(i=0;i<50;i++){
        if(score[i] == key_score) break;
    }
    
    int rank = i+1;

    if(rank <= 5)
        cout << "A+" << "\n";
    else if(rank <= 15)
        cout << "A0" << "\n";
    else if(rank <= 30)
        cout << "B+" << "\n";
    else if(rank <= 35)
        cout << "B0" << "\n";
    else if(rank <= 45)
        cout << "C+" << "\n";
    else if(rank <= 48)
        cout << "C0" << "\n";
    else if(rank <= 50)
        cout << "F" << "\n";
}