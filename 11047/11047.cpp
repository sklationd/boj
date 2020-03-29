#include <iostream>
#include <vector>
#include <string>
using namespace std;

int coin[11]={0,};

int main(){
    int N,C,i;
    cin >> N >> C;

    for(i=1;i<=N;i++)
        cin >> coin[N-i];

    int count = 0;
    int index = 0;
    int remain = C;
    while(remain > 0){
        int t = remain / coin[index];
        remain -= t*coin[index];
        count += t;
        index++;
    }
    cout << count;

}