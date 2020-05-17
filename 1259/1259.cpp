#include <iostream>
#include <math.h>
#include <string.h>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    while(1){
        cin >> N;
        if(N==0)
            break;
        else {
            int length = (int)log10(N) + 1;
            int half = length / 2;
            string number = to_string(N);
            bool result = true;

            for(int i=0;i<half;i++){
                if(!(number[i] == number[length-i-1])){
                    result = false;
                }
            }
            if(result)
                cout << "yes" << endl;
            else
                cout << "no" << endl;
            
        }
    }
}