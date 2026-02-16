#include <iostream>
using namespace std;
int gcd(int a, int b) {
    if (b == 0)
        return a;
    if (a == b)
        return a;
    if (a > b) {
        if (a % b == 0)
            return b;
        return gcd(a % b, b);
    } else {
        if (b % a == 0)
            return a;
        return gcd(a, b % a);
    }
}
int main(){
    int a=120,b=220;
    cout << gcd(a,b);
}