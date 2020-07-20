#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int isprime(int n){
	int j;
	if(n == 2)
			return 1;
	else if(n%2 != 0 && n!=1){
		for(j=3;j<floor(sqrt(n))+1;j++)
			if(n%j == 0){
				return 0;
			}
		return 1;
	}
	else
		return 0;
}


pair<int, int> gold(int N, vector<int> &p){
    for(int i=0;N-p[i]>=p[i];i++){
        int prime_1 = p[i];
        int candidate_prime_2 = N-p[i];
        if(binary_search(p.begin(), p.end(), candidate_prime_2))
            return make_pair(prime_1, candidate_prime_2);
    }
    return make_pair(-1,-1);
}

int main(){
    int i,N;
    vector<int> v;
    vector<int> p;

    while(1){
        scanf("%d", &N);
        if(N==0) break;
        v.push_back(N);
    }
    
    int max_N = *max_element(v.begin(), v.end());

    // Store the all prime number less than max_N
    for(i=3;i<=max_N;i++){
        if(isprime(i))
            p.push_back(i);
    }

    for(i=0;i<v.size();i++){
        pair<int, int> result = gold(v[i], p);
        printf("%d = %d + %d\n", v[i], result.first, result.second);
    }
}