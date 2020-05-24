#include <iostream>
#include <cstring>
#include <tuple>

using namespace std;

int N;
short paper[2188][2188] = {0,};

// compare 9 string return 1 when they are all "1" else return "0"
bool equal9(tuple<int ,int ,int> a,
            tuple<int ,int ,int> b,
            tuple<int ,int ,int> c,
            tuple<int ,int ,int> d,
            tuple<int ,int ,int> e,
            tuple<int ,int ,int> f,
            tuple<int ,int ,int> g,
            tuple<int ,int ,int> h,
            tuple<int ,int ,int> i) {
    
    tuple<int,int,int> a100 = make_tuple(1,0,0);
    tuple<int,int,int> a010 = make_tuple(0,1,0);
    tuple<int,int,int> a001 = make_tuple(0,0,1);

    return (a==a100 || a==a010 || a==a001) &&
            a==b &&
            b==c &&
            c==d &&
            d==e &&
            e==f &&
            f==g &&
            g==h &&
            h==i;
}

tuple<int, int, int> tuplesum(tuple<int ,int ,int> a,
                              tuple<int ,int ,int> b,
                              tuple<int ,int ,int> c,
                              tuple<int ,int ,int> d,
                              tuple<int ,int ,int> e,
                              tuple<int ,int ,int> f,
                              tuple<int ,int ,int> g,
                              tuple<int ,int ,int> h,
                              tuple<int ,int ,int> i){
    int first = get<0>(a) + get<0>(b) + get<0>(c) + get<0>(d) + get<0>(e) + get<0>(f) + get<0>(g) + get<0>(h) + get<0>(i);
    int second = get<1>(a) + get<1>(b) + get<1>(c) + get<1>(d) + get<1>(e) + get<1>(f) + get<1>(g) + get<1>(h) + get<1>(i); 
    int third = get<2>(a) + get<2>(b) + get<2>(c) + get<2>(d) + get<2>(e) + get<2>(f) + get<2>(g) + get<2>(h) + get<2>(i); 

    return make_tuple(first,second,third);
}

tuple<int, int, int> divconq(int x, int y, int size){
    if(size == 1){
        if(paper[x][y]==1)
            return make_tuple(1,0,0);
        else if(paper[x][y]==0)
            return make_tuple(0,1,0);
        else 
            return make_tuple(0,0,1); 
    } else {
        int offset = size/3;
        int doffset = offset*2;
        tuple<int, int ,int> ld, lm, lu, md, mm, mu, rd, rm, ru;

        ld = divconq(x,y,offset);
        lm = divconq(x,y+offset,offset);
        lu = divconq(x,y+doffset,offset);
        md = divconq(x+offset,y,offset);
        mm = divconq(x+offset,y+offset,offset);
        mu = divconq(x+offset,y+doffset,offset);
        rd = divconq(x+doffset,y,offset);
        rm = divconq(x+doffset,y+offset,offset);
        ru = divconq(x+doffset,y+doffset,offset);

        if(equal9(ld, lm, lu, md, mm, mu, rd, rm, ru)){
            return ld;
        } else {
            return tuplesum(ld, lm, lu, md, mm, mu, rd, rm, ru);
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

    tuple<int, int, int> result = divconq(0,0,N);
    cout << get<2>(result) << endl;
    cout << get<1>(result) << endl;
    cout << get<0>(result);
}