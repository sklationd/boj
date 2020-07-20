#include <iostream>
#include <string.h>
#include <string>

#define BUF_SIZE 1000

using namespace std;

int main(){
    int i;

    char buf[BUF_SIZE]={0,};
    string result = "";
    while(fgets(buf,BUF_SIZE,stdin)){
        int length = strlen(buf);
        for(i=0;i<length;i++){
            switch(buf[i]) {
                case '0':
                    result += "000";
                    break;
                case '1':
                    result += "001";
                    break;
                case '2':
                    result += "010";
                    break;
                case '3':
                    result += "011";
                    break;
                case '4':
                    result += "100";
                    break;
                case '5':
                    result += "101";
                    break;
                case '6':
                    result += "110";
                    break;
                case '7':
                    result += "111";
                    break;
            }
        }
    }

    // Remove leading zeros
    i=0;
    while(result[i++]=='0');
    result.erase(0,i-1);
    
    // Handle zero case
    if(result.length() == 0) result = "0";
    
    // Print result
    cout << result <<endl;

    return 0;
}