#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int N,C;
int weight[31] = {0,};

vector<int> leftarr;
vector<int> rightarr;

void cleft(int i, int sum){
    if(sum > C)
        return;
    else{
        if(i==(N/2)){
            leftarr.push_back(sum);
            return;
        } else {
            cleft(i+1, sum+weight[i]);
            cleft(i+1, sum);
        }
    }
}

void cright(int i, int sum){
    if(sum > C)
        return;
    else{
        if(i==N){
            rightarr.push_back(sum);
            return;
        } else {
            cright(i+1, sum+weight[i]);
            cright(i+1, sum);
        }
    }
}

int main(){
    int i,j;
    cin >> N >> C;
    for(i=0;i<N;i++)
        cin >> weight[i];
    sort(weight+0,weight+N);
    int mid = (N/2);
    cleft(0, 0);
    cright(mid, 0);

    int result = 0;
    for(i=0;i<leftarr.size();i++)
        for(j=0;j<rightarr.size();j++)
            if(leftarr[i]+rightarr[j] <= C)
                result++;
            
    cout << result;
}