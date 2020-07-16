#include <iostream>

int main(){
    int N,M,i,j;
    scanf("%d%d",&N,&M);
    for(i=0;i<N;i++){
        printf("%d",i*M+1);
        for(j=1;j<M;j++){
            printf(" %d",i*M + j + 1);
        }
        printf("\n");
    }
}