#include <bits/stdc++.h>
using namespace std;

int gcd(int a,int b){
    int result=min(a,b);

    while(result>0){
        if(a % result==0 && b % result==0){
            break;
        }
        result--;
    }
    return result;
}
int main(){
    int a=120,b=220;
    cout << gcd(a,b) << endl;
}