#include <iostream>
#include <deque>
#include <cstring>
#include <cstdlib>
#include <assert.h>

using namespace std;
int main(){
    // for fast io 
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N,i;
    cin >> N;
    for(i=0;i<N;i++){
        string com;
        cin >> com;
        int num;
        cin >> num;
        char array[400050];
        cin >> array;

        deque<int> dq;
        char *ptr = strtok(array, "[] ,");
        int index = 0;
        while(ptr!=NULL){
            dq.push_back(atoi(ptr));
            ptr = strtok(NULL, "[] ,");
        }

        bool reverse = false;
        bool result = true;
        for(int j=0;j<com.length();j++){
            char C = com[j];
            if(C=='R')
                reverse = !reverse;
            else if(C=='D'){
                if(dq.size()==0){
                    cout << "error" << endl;
                    result = false;
                    break;
                }
                else if(reverse) dq.pop_back();
                else dq.pop_front();
            } else 
                assert(0);
        }

        // print result
        if(result){
            cout << '[';

            while(dq.size()){
                if(reverse){
                    cout << dq.back();
                    dq.pop_back();

                } else {
                    cout << dq.front();
                    dq.pop_front();
                }
                if(dq.size()){
                    cout << ",";
                }
            }

            cout << ']' << endl;
        }

    }
}   