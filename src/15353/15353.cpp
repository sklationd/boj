#include <iostream>
#include "string.h"

using namespace std;

int add(char *a, char *b, char *r){
    int la = strlen(a);
    int lb = strlen(b);

    int i;
    int c = 0;

    for(i=1;i<=la+1;i++){
        int T = c;
        if(la - i >= 0){
            T += (a[la-i] - '0');
        }
        if(lb - i >= 0){
            T += (b[lb - i] - '0');
        }
        c = T/10;
        T %= 10;
        r[i-1] = (char)(T+'0');
    }
    if(r[la] == '0'){
        r[la] = '\0';
        i--;
    }

    return i-1;
}

int main(){
    char a[10001];
    char b[10001];
    char r[10001];

    cin >> a >> b;

    int l;
    if(strlen(a) > strlen(b))
        l = add(a,b,r);
    else
        l = add(b,a,r);    

    for(int i=l-1;i>=0;i--){
        printf("%c",r[i]);
    }

    return 0;
}