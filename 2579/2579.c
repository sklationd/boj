#include <stdio.h>

int score[300]={0,};
int result[300]={0,};

int max(int a, int b){
    return a>b?a:b;
}

int dp(int n){
    if(n==1){
        result[0]=score[0];
        return result[0];
    } else if (n==2) {
        result[1] = score[0]+score[1];
        return result[1];
    } else if (n==3) {
        int temp = max(score[0]+score[2],score[1]+score[2]);
        result[2]=temp;
        return temp;
    } else if (result[n-1]!=0) {
        return result[n-1];
    } else {
        int temp = max(dp(n-3)+score[n-2]+score[n-1], dp(n-2)+score[n-1]);
        result[n-1]=temp;
        return temp;
    }
}

int main(){
    int n,i;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",score+i);
    printf("%d",dp(n));
}