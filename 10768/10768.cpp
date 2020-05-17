#include <iostream>

using namespace std;

void before(){
    printf("Before");
}


void after(){
    printf("After");
}

void special(){
    printf("Special");
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int m,d;
    cin >> m >> d;
    if(m < 2){
        before();              
    } else if(m==2){
        if(d<18)
            before();
        else if(d==18)
            special();
        else{
            after();
        }
    } else {
        after();
    }
}

