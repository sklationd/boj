#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>
#include <list>

using namespace std;

bool cmp(const std::string &lhs, const std::string &rhs) { 
   return (lhs.size() == rhs.size()) ? lhs < rhs
                                      : lhs.size() < rhs.size();
}

int main(){
    vector<string> l;
    vector<string> s;
    vector<string> intersection;

    int N,M,i;
    cin >> N >> M;

    l.reserve(N);
    s.reserve(M);

    for(i=0;i<N;i++){
        string temp;
        cin >> temp;
        l.push_back(temp);
    }

    for(i=0;i<M;i++){
        string temp;
        cin >> temp;
        s.push_back(temp);
    }

    sort(l.begin(), l.end(), cmp);
    sort(s.begin(), s.end(), cmp);

    set_intersection(l.begin(), l.end(),
                     s.begin(), s.end(),
                     back_inserter(intersection),
                     cmp);

    sort(intersection.begin(), intersection.end());

    cout << intersection.size() << endl;
    for(i=0;i<intersection.size();i++) {
        cout << intersection[i] << endl;
    }
}