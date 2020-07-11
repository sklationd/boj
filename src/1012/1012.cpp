#include <iostream>
#include <cstring>
using namespace std;

int W,H,B;
int garden[52][52] = {0,};
int check[52][52] = {0,};
int result = 0;

int dfs(int x, int y){

    if(check[x][y])
        return 0;
    else if(x>W || y>H || x<1 || y<1){
        check[x][y] = 1;
        return 0;
    } else if(garden[x][y] == 0){
        check[x][y] = 1;
        return 0;
    } else {
        check[x][y] = 1;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);
        return 1;
    }
}

int main(){
    int N,i,j,k;
    cin >> N;
    for(i=0;i<N;i++){
        cin >> W >> H >> B;
        for(j=0;j<B;j++){
            int x,y;
            cin >> x >> y;
            garden[x+1][y+1] = 1;
        }
        for(j=1;j<=W;j++){
            for(k=1;k<=H;k++){
                result += dfs(j,k);
            }
        }
        cout << result << "\n";
        
        result = 0;
        memset(check,0,sizeof(check));
        memset(garden,0,sizeof(garden));
    }
}