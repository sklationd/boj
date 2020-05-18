#include <iostream>

using namespace std;

int min2(int a, int b){
    return a>b?b:a;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;

    int c2 = 0;
    int c5 = 0;
    for(i=2;i<=N;i++){
        int temp = i;
        while(temp%2==0 && temp!=0){
            c2++;
            temp/=2;
        }
        while(temp%5==0 && temp!=0){
            c5++;
            temp/=5;
        }
    }
    cout << min2(c2,c5);
}