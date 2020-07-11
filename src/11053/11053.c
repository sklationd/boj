#include <stdio.h>

int input[1001] = {0,}; 
int dp[1001] = {1,0,};
int main(){
    int n,i,j;
    int result = 0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
        scanf("%d",input+i);
    for(i=1;i<=n;i++){
        int max = 0;
        for(j=0;j<i;j++){
            if(input[i]>input[j]){
                if(max<dp[j])
                    max = dp[j];
            }
        }
        dp[i] = max + 1;
        if(result < dp[i])
            result = dp[i];
    }
    printf("%d",result);
}