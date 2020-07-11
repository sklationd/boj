#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000000
#define D 1000000007

using namespace std;

typedef long long int ll;

ll init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = a[start];
    } else {
        return tree[node] = (init(a, tree, 2*node, start, (start+end)/2) * init(a, tree, 2*node+1, (start+end)/2 + 1, end))%D;
    }
}

ll sum_st(vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start){
        return 1;
    } 
    if( left<=start && end<=right){
        return tree[node];
    } 
    return sum_st(tree, node*2, start, (start+end)/2, left, right) * sum_st(tree, node*2+1, (start+end)/2+1, end, left, right)%D;
}

ll update(vector <ll> &tree, int node, int start, int end, int index, ll value){
    if(index < start || index > end) 
        return tree[node];
    if(start == end)
        return tree[node] = value;
    return tree[node] = (update(tree, node*2, start, (start+end)/2, index, value) * update(tree, node*2+1, (start+end)/2+1, end, index, value))%D;
}

int main(){
    int N,M,K;
    scanf("%d%d%d",&N,&M,&K);

    vector<ll> array(N);
    int h = (int) ceil(log2(N));  
    vector<ll> tree(2<<h);

    for(int i=0;i<N;i++){
        ll temp;
        cin >> temp;
        array[i] = temp;
    }
    
    init(array, tree, 1, 0, N-1);

    for(int i=0;i<M+K;i++){
        ll start, end, comm;
        scanf("%lld%lld%lld", &comm, &start, &end);
        if(comm == 1) { // change value
            if(array[start-1] == 0){
                update(tree, 1, 0, N-1, start-1, end);
            }
            else {
                update(tree, 1, 0, N-1, start-1, end);
            }
        } else { // print sum of interval 
            printf("%lld\n", sum_st(tree, 1, 0, N-1, start-1, end-1));
        }
    }
}