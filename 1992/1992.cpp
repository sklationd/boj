#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int N;
char paper[65][65] = {0,};

bool equal4(string a, string b, string c, string d){
    return (!a.compare("1") || !a.compare("0")) && !a.compare(b) && !b.compare(c) && !c.compare(d);
}

string divconq(int x, int y, int size){
    if(size == 1){
        if(paper[x][y] == '1')
            return "1";
        else
            return "0";    
    } else {
        int offset = size/2;
        string ld,lu,rd,ru;
        ld = divconq(x,y,offset);
        lu = divconq(x,y+offset,offset);
        rd = divconq(x+offset,y,offset);
        ru = divconq(x+offset,y+offset,offset);
        if(equal4(ld,lu,rd,ru)){
            return ld;
        } else {
            return "(" + ld + lu + rd + ru + ")";
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

    string result = divconq(0,0,N);
    cout << result;
}