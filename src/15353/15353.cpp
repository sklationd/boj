#include <iostream>
#include <string>
#include "string.h"

using namespace std;

typedef long long int ll;

int add(string &a, string &b, string &r){
    int la = a.size();
    int lb = b.size();

    int i;
    int c = 0;
    for(i=1;i<=la+1;i++){
        int T = c;
        if(la - i >= 0)
            T += (a[la-i] - '0');
        if(lb - i >= 0)
            T += (b[lb - i] - '0');
        c = T/10;
        cout << c << endl;
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
    string a;
    string b;
    string r;

    cin >> a >> b;
    int l;
    if(a.size() > b.size())
        l = add(a,b,r);
    else
        l = add(b,a,r);    

    for(int i=l-1;i>=0;i--){
        printf("%c",r[i]);
    }

    return 0;
}