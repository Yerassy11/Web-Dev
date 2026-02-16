#include <bits/stdc++.h>
using namespace std;
bool isPrime(int n){
    if(n<=1) return false;
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0)
            return false;
    }
    return true;
}

int main() {
    int n;
    cin >> n;
    vector<int>primes;
    primes.push_back(0);
    vector<int>sp;

    for(int i=2;i<100000;i++){
        if(isPrime(i)) primes.push_back(i);
    }
    for(int j=2;j<primes.size();j++){
        if(isPrime(j)) sp.push_back(primes[j]);
    }
    cout << sp[n-1];


}