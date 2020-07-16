#include <iostream>
#include <cstring>

#define S 20

using namespace std;

bool dat[S] = {false,};

void add(short x){
    dat[x-1]=true;
}

void remove(short x){
    dat[x-1]=false;
}

void check(short x){
    if(dat[x-1]) cout << 1 << "\n";
    else cout << 0 << "\n";
}

void toggle(short x){
    dat[x-1] = !dat[x-1];
}

void all(){
    memset(dat,true,sizeof(bool)*S);
}

void empty(){
    memset(dat,false,sizeof(bool)*S);
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;

    for(i=0;i<N;i++){
        string cmd;
        short x;
        cin >> cmd;
        if(!cmd.compare("add")){
            cin >> x;
            add(x);
        } else if(!cmd.compare("remove")) {
            cin >> x;
            remove(x);
        } else if(!cmd.compare("check")) {
            cin >> x;    
            check(x);
        } else if(!cmd.compare("toggle")) {
            cin >> x;
            toggle(x);
        } else if(!cmd.compare("all")) all();
        else if(!cmd.compare("empty")) empty();
    }
}