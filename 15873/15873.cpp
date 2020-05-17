#include <iostream>

using namespace std;
char b[4];
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    
    cin >> b;
    if(b[1] == '0'){
        if(b[3]=='0'){
            printf("20");
        }
        else
            printf("%c%c",b[0],b[2]);
    } else if(b[2] == '0'){
        printf("%c%c", b[1],b[0]);
    } else {
        printf("%d", ((int)b[0] - '0') + ((int)b[1] - '0'));
    }
}