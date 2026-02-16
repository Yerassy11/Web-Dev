#include <bits/stdc++.h>
using namespace std;
vector<int> sieve(int n){
    if(n<2) return {};
    vector<char> is_prime(n+1,true);
    is_prime[0]=is_prime[1]=false;

    for (int p=2;1ll*p*p<=n;p++){
        if(!is_prime[p]) continue;
        for (long long j=1LL*p*p;j<=n;j+=p){
            is_prime[(size_t)j]=false;
        }
    }
    vector<int>primes;
    for(int i=2;i<=n;i++){
        if(is_prime[i]) primes.push_back(i);
    }
    return primes;
    
}