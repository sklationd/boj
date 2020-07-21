#include <iostream>

using namespace std;

int main(){
    int N,i;
    scanf("%d",&N);
    for(i=0;i<N;i++){
        int a,b;
        scanf("%d,%d",&a, &b);
        printf("%d\n",a+b);
    }
}