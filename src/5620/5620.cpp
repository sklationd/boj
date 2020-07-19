#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
    int x, y;
};

int distance(Point &a, Point &b){
    return  (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
}

struct Comp {
    bool comp_in_x;
    Comp(bool b) : comp_in_x(b) {}
    bool operator()(Point &p, Point &q) {
        return (this->comp_in_x? p.x < q.x : p.y < q.y);
    }
};
 
int solve(vector<Point>::iterator it, int n){
    if(n==2){
        return distance(it[0], it[1]);
    } else if(n==3){
        return min({distance(it[0],it[1]), 
                    distance(it[0],it[2]), 
                    distance(it[1],it[2])});
    } else {
        int line = (it[n/2 - 1].x + it[n/2].x)/2;

        int l = solve(it, n/2);
        int r = solve(it+n/2, n - n/2);
        int d = min(l,r);

        vector<Point> mid;
        mid.reserve(n);

        for(int i=0;i<n;i++){
            int t = line - it[i].x;
            if(t*t < d){
                mid.push_back(it[i]);
            }
        }

        sort(mid.begin(), mid.end(), Comp(false));
        int s = mid.size();

        for(int i=0;i<s-1;i++){
            for (int j = i + 1; j < s && (mid[j].y - mid[i].y)*(mid[j].y - mid[i].y) < d; j++){
                    int mid_d = distance(mid[i], mid[j]);
                    if(d > mid_d)
                        d = mid_d;
            }
        }

        return d;
    }
}

int main(void){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    vector<Point> points(n);

    for(auto it = points.begin(); it!=points.end(); it++){
        cin >> it->x >> it->y;
    }

    // sort with x coordinate firstly, y coordinate secondly.
    sort(points.begin(), points.end(), Comp(true));

    cout << solve(points.begin(), n) << endl;
    
    return 0;
}