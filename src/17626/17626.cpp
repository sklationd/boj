#include <iostream>
#include <cmath>

using namespace std;

int result[50001] = {0,};

int F(int n){
    if(n==0 || n==1) 
        return n;
    if(result[n]!=0) 
        return result[n];
    
    int min = 4;
    
    for(int i=floor(sqrt(n));i>0;i--){
        int temp = F(n-i*i) + 1;
        if(min > temp) min = temp;
        if(min == 1) break; 
    }

    result[n] = min;
    return min;
}

int main(){
    int N;
    cin >> N;
    cout << F(N) << "\n";
}