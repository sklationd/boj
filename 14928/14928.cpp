#include<cstdio>

int n;
char buf[1<<20];
int main(){
	int c = fread(buf,1,1<<20,stdin);
	for(int i=0;i<c-1; ++i) n=(n*10 + (buf[i]-'0'))%20000303;
	printf("%d", n);
}