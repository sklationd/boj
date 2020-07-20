#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool is_digit(string str) {
    return atoi(str.c_str()) != 0 || str.compare("0") == 0;
}

bool cmp(const pair<string,int> &a, const pair<string,int> &b){
    return a.first > b.first;
}

int binary_search_find_index(vector<pair<string,int>> &v, pair<string,int> data) {
    auto it = std::lower_bound(v.begin(), v.end(), data, cmp);
    if (it == v.end() || (*it).first.compare(data.first) ) {
        return -1;
    } else {
        std::size_t index = std::distance(v.begin(), it);
        return index;
    }   
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,M,i;
    cin >> N >> M;

    vector<pair<string,int>> lex_dogam;
    vector<pair<string,int>> num_dogam;

    for(i=0;i<N;i++){
        string pocketmon_name;
        cin >> pocketmon_name;
        lex_dogam.push_back(make_pair(pocketmon_name,i+1));
        num_dogam.push_back(make_pair(pocketmon_name,i+1));
    }

    sort(lex_dogam.begin(), lex_dogam.end(), cmp);

    for(i=0;i<M;i++){
        string input;
        cin >> input;
        if(is_digit(input)){
            cout << num_dogam[atoi(input.c_str()) - 1].first << "\n";
        } else {
            int index = binary_search_find_index(lex_dogam, make_pair(input,0));
            cout << lex_dogam[index].second << "\n";
        }
    }
}