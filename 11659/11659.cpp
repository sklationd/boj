#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000000

using namespace std;

typedef long long int ll;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    } else {
        return tree[node] = init(a, tree, 2*node, start, (start+end)/2) + init(a, tree, 2*node+1, (start+end)/2 + 1, end);
    }
}

ll sum_st(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start){
        return 0;
    } 
    if( left<=start && end<=right){
        return tree[node];
    } 
    return sum_st(tree, node*2, start, (start+end)/2, left, right) + sum_st(tree, node*2+1, (start+end)/2+1, end, left, right);
}

int main(){
    int N,M;
    scanf("%d%d",&N,&M);

    vector<ll> array(N);
    int h = (int) ceil(log2(N));  
    vector<ll> tree(2<<h);

    for(int i=0;i<N;i++){
        ll temp;
        cin >> temp;
        array[i] = temp;
    }
    
    init(array, tree, 1, 0, N-1);

    for(int i=0;i<M;i++){
        ll start, end;
        scanf("%lld%lld", &start, &end); // print sum of interval 
        printf("%lld\n", sum_st(tree, 1, 0, N-1, start-1, end-1));
    }
}