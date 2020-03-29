#include <iostream>
#include <ctime>
using namespace std;

int main(){
    time_t now = time(0);
    tm *ltm = localtime(&now);
    cout << 1900 + ltm->tm_year << endl;
    cout << 1 + ltm->tm_mon<< endl;
    cout << ltm->tm_mday << endl;
}