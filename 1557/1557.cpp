#include <iostream>

using namespace std;

typedef long long ll;

const int MX = 1e5;
int mobius[MX+1];
// N 이하의 square free number의 수
ll solve(ll N){
  ll ret = 0;
  for(int i = 1; i*i <= N; i++) ret += mobius[i] * (N/(i*i));
  return ret;
}

int main(void) {
    int K;
    cin >> K;
    fill(mobius+1,mobius+MX+1,1);
    for(int i = 2; i*i <= MX; i++){
        if(mobius[i]==1){
            for(int j = i; j <= MX; j+=i) mobius[j] *= -i;
            for(int j = i*i; j <= MX; j+=i*i) mobius[j] = 0;
        }
    }
    for(int i = 2; i <= MX; i++){
        if(mobius[i] == i) mobius[i] = 1;
        else if(mobius[i] == -i) mobius[i] = -1;
        else if(mobius[i] < 0) mobius[i] = 1;
        else if(mobius[i] > 0) mobius[i] = -1;
    }  
    ll st = 1;
    ll en = 2000'000'000;
    while(st<en){
        ll mid = (st+en)>>1;
        ll val = solve(mid);    
        if(val > K) en = mid-1;
        else if(val == K) en = mid;
        else st = mid+1;
    }
    cout << st;
}