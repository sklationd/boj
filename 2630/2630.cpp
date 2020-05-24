#include <iostream>

using namespace std;

int N;
int paper[129][129] = {0,};

bool equal4(pair<int, int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d){
    return (a==make_pair(1,0) || a==make_pair(0,1)) && a==b && b==c && c==d;
}

pair<int,int> divconq(int x, int y, int size){
    if(size == 1){
        if(paper[x][y])
            return make_pair(0,1);
        else
            return make_pair(1,0);    
    } else {
        int offset = size/2;
        pair<int, int> ld,lu,rd,ru;
        ld = divconq(x,y,offset);
        lu = divconq(x,y+offset,offset);
        rd = divconq(x+offset,y,offset);
        ru = divconq(x+offset,y+offset,offset);
        if(equal4(ld,lu,rd,ru)){
            return ld;
        } else {
            return make_pair(ld.first+lu.first+rd.first+ru.first, ld.second+lu.second+rd.second+ru.second);
        }
    }
}


int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);


    cin >> N;
    for(int i=0;i<N;i++){
        for(int j=0;j<N;j++){
            cin >> paper[i][j];
        }
    }

    pair<int, int> result = divconq(0,0,N);
    cout << result.first << "\n" << result.second;
}