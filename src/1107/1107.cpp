#include <iostream>
#include <vector>
#include <cmath>
#define fastio ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;

int num_digit(int n){
	if(n==0)
		return 1;
	else{
		return floor(log10(n))+1;
	}
}

bool check(int num){
	if(num==0)
		return false;
	while(num){
		int r = num%10;
		num/=10;
		if(num!=0 && r==0)
			return false;
	}
	return true;
}

int main(){
    // for fast io 
    fastio;
	
	int S = 100;
	int D;
	cin >> D;

    int N,i;
	bool all_digit[10] = {false,};
    cin >> N;
	bool zero_broken = false;
    for(i=0;i<N;i++){
		int temp;
		cin >> temp;
		if(temp == 0)
			zero_broken = true;
        else 
			all_digit[temp] = true;
    }

	// available digits
	int digits[10]={0,};
	int count = 0;
	for(i=0;i<10;i++){
		if(!all_digit[i]){
			digits[count++] = i;
		}
	}
	int min = abs(S-D);
	for(int d6=0;d6<count;d6++){
		for(int d5=0;d5<count;d5++){
			for(int d4=0;d4<count;d4++){
				for(int d3=0;d3<count;d3++){
					for(int d2=0;d2<count;d2++){
						for(int d1=0;d1<count;d1++){
							int num = digits[d6]*100000 
							        + digits[d5]*10000 
									+ digits[d4]*1000 
									+ digits[d3]*100 
									+ digits[d2]*10 
									+ digits[d1];
							int d = num_digit(num) + abs(num - D);
							if(min > d && (!zero_broken || check(num)))
								min = d;
						}
					}
				}
			}
		}
	}
	cout << min << "\n";
	return 0;
}
