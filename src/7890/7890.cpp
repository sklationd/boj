#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iterator>

#define D 2

using namespace std;

class Point{
    public:
        int x=-1;
        int y=-1;
        int i=-1;

    Point(int x_, int y_, int i_){
        x = x_;
        y = y_;
        i = i_;
    }
};

bool cmp_x(Point &a, Point &b){
    return a.x < b.x;   
}

bool cmp_y(Point &a, Point &b){
    return a.y < b.y;
}

bool cmp_i(Point &a, Point &b){
    return a.i < b.i;
}

void kdtree(vector<Point> &P, vector<Point> &tree, int depth, int index){
    if(P.empty()) 
        return ;

    // axis 0: x axis
    // axis 1: y axis
    int axis = depth % D;

    // sort points with appropriate axis
    if(axis) sort(P.begin(), P.end(), cmp_y);
    else sort(P.begin(), P.end(), cmp_x);
    int median = P.size() / 2;

    tree[index].x = P[median].x;
    tree[index].y = P[median].y;
    tree[index].i = P[median].i;

    // size is less than equal to 1
    if(P.size() <= 1)
        return;

    // if size is 2 than choose right(higher) point for candidate of axis
    if(P.size() == 2){
        vector<Point> lhs(P.begin(), P.begin() + 1);
        kdtree(lhs, tree, depth+1, 2*index+2);
    } else {
        vector<Point> lhs(P.begin(), P.begin()+median);
        vector<Point> rhs(P.begin() + median + 1, P.end());
        kdtree(lhs, tree, depth+1, 2*index+1);
        kdtree(rhs, tree, depth+1, 2*index+2);
    }
}

// int min_d(vector<Point> &tree, Point p){
    
// }

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T,N,i,j;
    cin >> T;

    for(i=0;i<T;i++){
        cin >> N;

        vector<Point> P;
        vector<Point> tree;

        P.reserve(N);
        tree.reserve(4*N);

        for(j=0;j<N;j++){
            int x,y;
            cin >> x >> y;
            P.push_back(Point(x,y,j));
        }

        kdtree(P, tree, 0, 0);
        sort(P.begin(), P.end(), cmp_i);

        for(j=0;j<N;j++){
            cout << min_d(tree, P[j]) << "\n";
        }
        
    }
}