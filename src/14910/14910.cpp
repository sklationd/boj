#include <iostream>

using namespace std;

typedef long long int ll;

int main(){
    int prev;
    int current;
    scanf("%d",&prev);
    bool result = true;
    while(scanf("%d",&current) == 1){
        if(current == ' ') continue;
        if(prev > current) {
            result = false;
            break;
        }
        prev = current;
    }
    if(result) cout << "Good\n";
    else cout << "Bad\n";
}