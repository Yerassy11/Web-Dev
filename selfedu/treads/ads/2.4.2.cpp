#include <iostream>
using namespace std;
int main(){
    char ar[7];
    ar[0]='a';ar[1]='b';ar[2]='c';ar[3]='d';ar[4]='e';ar[5]='f';ar[6]='g';
    for (int i = 7; i > 2; --i) {
        ar[i] = ar[i - 1];
    }
    ar[2]='#';
    for(char x:ar){
        cout << x << " ";
    }
}