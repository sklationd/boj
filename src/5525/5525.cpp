#include <iostream>
#include <string>
using namespace std;

int main(){
    int N,M,i,j;
    scanf("%d%d",&N,&M);
    int count = 0;
    i=0;

    char c;
    while((c = getchar())!=EOF){
        if(c=='I'){
            int C = 0;
            while(1){
                if(getchar()=='O')
                    if(getchar()=='I')
                        C++;
                    else
                        break;
                else {
                    fseek(stdin,-1,SEEK_CUR);
                    break;                    
                }
            }
            count += max(0,C-N+1);
        }
    }
    printf("%d\n",count);
}