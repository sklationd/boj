#include <iostream>
#include <string>

using namespace std;
int dp[1001][1001] = {0,};

int max2(int a, int b){
    return a>b?a:b;
}

int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a;
    string b;

    cin >> a;
    cin  >> b;

    int Alength = a.length();
    int Blength = b.length();
    for(int i=0;i<Alength;i++){
        int max = 0;
        for(int j=0;j<Blength;j++){
            if(a[i]!=b[j]){
                dp[i+1][j+1] = max2(dp[i+1][j],dp[i][j+1]);
            } else {
                dp[i+1][j+1] = dp[i][j] + 1;
            }
        }
    }
    int LCS_length = 0;
    for(int i=1;i<=Blength;i++){
        if(LCS_length < dp[Alength][i])
            LCS_length = dp[Alength][i];
    }
    
    cout << LCS_length;

    if(LCS_length){
        cout << endl;
        int count = LCS_length;
        string result = "";
        for(int i=Alength;i>0;i--){
            for(int j=Blength;j>0;j--){
                if(dp[i][j] == count && dp[i-1][j] == count-1 && dp[i][j-1] == count-1 && dp[i-1][j-1] == count-1){
                    result = a[i-1] + result;
                    count--;
                    break;
                }
            }
        }
        cout << result;
    }

}