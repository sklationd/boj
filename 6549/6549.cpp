#include <iostream>
#include <vector>
#include <cmath>

#define MAX 1000000000

typedef long long int ll;
using namespace std;

int N;

ll min3(ll a, ll b, ll c){
    return a<b?(c<a?c:a):(c<b?c:b);
}


ll max3(ll a, ll b, ll c){
    return a>b?(c>a?c:a):(c>b?c:b);
}

int init(vector<ll> &a, vector<ll> &tree, int node, int start, int end){
    if(start == end){
        return tree[node] = start;
    } else {
        int lc = init(a, tree, 2*node, start, (start+end)/2);
        int rc = init(a, tree, 2*node+1, (start+end)/2 + 1, end);

        if(a[lc] < a[rc])
            return tree[node] = lc;
        else
            return tree[node] = rc;        
    }
}

int min_st(vector<ll> &a, vector <ll> &tree, int node, int start, int end, int left, int right){
    if(left>end || right<start){
        return -1;
    } 

    if( left<=start && end<=right){
        return tree[node];
    } 

    int lc = min_st(a, tree, node*2, start, (start+end)/2, left, right);
    int rc = min_st(a, tree, node*2+1, (start+end)/2+1, end, left, right);
    
    if(lc < 0)
        return rc;
    else if(rc < 0)
        return lc;
    else {
        if(a[lc] < a[rc])
            return lc;
        else
            return rc;            
    }


}

ll dq(int start, int end, vector<ll> &height, vector<ll> &tree){
    if(start == end){
        return height[start];
    } else {
        ll leftside = 0;
        ll rightside = 0;

        int pivot = min_st(height, tree, 1, 0, N-1, start, end);

        // result with minimal height on whole section
        ll minheight_S    = height[pivot] * (end-start+1);

        // maximum result of left histogram
        if(pivot > start)
            leftside  = dq(start, pivot-1, height, tree);
        
        // maximum result of right histogram
        if(pivot < end)
            rightside = dq(pivot+1, end, height, tree);
        
        ll result = max3(leftside, rightside, minheight_S);

        return result;
    }
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        cin >> N;

        if(N==0)
            break;

        vector<ll> height(N);
        int h = (int) ceil(log2(N));  
        vector<ll> tree(2<<h);
        
        for(int i=0;i<N;i++){
            ll temp;
            cin >> temp;
            height[i] = temp;
        }    

        init(height, tree, 1, 0, N-1);

        ll result = dq(0, N-1, height, tree);

        cout << result << endl;
    }

    return 0;
}