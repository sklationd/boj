#include <iostream>
#include <stack>
using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while(1){
        stack<char> s;
        string input;
        getline(cin, input);
        if(input.size()==1 && input[0]=='.')
            break;
        else {
            bool result = true;
            for(int i=0;i<input.size();i++){
                if(input[i]=='['){ 
                    s.push('[');
                } else if(input[i]==']'){
                    if(s.size()){
                        if(s.top()=='[')
                            s.pop();
                        else{
                            result = false;
                            break;                 
                        }
                    } else {
                        result = false;
                    }
                } else if(input[i]=='('){ 
                    s.push('(');
                } else if(input[i]==')'){
                    if(s.size()){
                        if(s.top()=='(')
                            s.pop();
                        else{
                            result = false;
                            break;                 
                        }
                    } else {
                        result = false;
                    }
                } 
            }

            if(s.size())
                result = false;

            if(result)
                cout << "yes" << endl;
            else
                cout << "no"  << endl;            
        }
    }
}