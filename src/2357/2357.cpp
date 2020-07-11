#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000000
#define MIN 0
using namespace std;

typedef long long int ll;

pair<ll,ll> init(vector<ll> &a, vector<pair<ll,ll>> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = make_pair(a[start],a[start]);
    } else {
        pair<ll,ll> left = init(a, tree, 2*node, start, (start+end)/2);
        pair<ll,ll> right = init(a, tree, 2*node+1, (start+end)/2 + 1, end);
        return tree[node] = make_pair(min(left.first, right.first), max(left.second, right.second));
    }
}

pair<ll,ll> minmax_st(vector <pair<ll,ll>> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start){
        return make_pair(MAX,MIN);
    } 
    if( left<=start && end<=right){
        return tree[node];
    }

    pair<ll, ll> lc = minmax_st(tree, node*2, start, (start+end)/2, left, right);
    pair<ll, ll> rc = minmax_st(tree, node*2+1, (start+end)/2+1, end, left, right);
    ll minV = min(lc.first, rc.first);
    ll maxV = max(lc.second, rc.second);
    return make_pair(minV, maxV);
}

int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    vector<ll> array(N);
    int h = (int) ceil(log2(N));  
    vector<pair<ll,ll>> tree(2<<h);

    for(int i=0;i<N;i++){
        ll temp;
        cin >> temp;
        array[i] = temp;
    }
    
    init(array, tree, 1, 0, N-1);

    for(int i=0;i<M;i++){
        int start, end;
        scanf("%d %d", &start, &end);
        pair<ll,ll> result = minmax_st(tree, 1, 0, N-1, start-1, end-1);
        printf("%lld %lld\n", result.first, result.second);
    }
}