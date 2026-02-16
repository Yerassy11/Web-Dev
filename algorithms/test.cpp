#include <bits/stdc++.h>
using namespace std;
vector<int>RabinKarp(string text,string pat){
    int n=text.size();
    int m=pat.size();

    if(m>n) return {};
    
    const long long P=257;
    const long long MOD=10000007;

    long long hash_p=0;
    long long hash_window=0;

    long long power=1;

    for(int i=0;i<m;i++){
        power=(power*P)%MOD;
    }

    for(int i=0;i<m;i++){
        hash_p=(hash_p*P+(unsigned char)pat[i])%MOD;
        hash_window=(hash_p*P+(unsigned char)text[i])%MOD;
    }

    vector<int>occurences;

    for(int i=0;i<=n-m;i++){

        if(hash_window==hash_p){
            if(text.compare(i,m,pat)==0){
                occurences.push_back(i);
            }
        }

        if(i<n-m){

            hash_window=(hash_window-(unsigned char)text[i]*power)%MOD;
            if(hash_window<0)hash_window+=MOD;

            hash_window=(hash_window*P+(unsigned char)text[i+m])%MOD;
        }
    }
    return occurences;
    
}

int main(){
    int n;
    cin >> n;

}