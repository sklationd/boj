#include <stdio.h>
int main(){
	int x,i=-1000001;
	while(scanf("%d", &x)){
		if(x<=i) break;
		else i=x;
	}
	if (x<i) printf("Bad");
	else printf("Good");
}