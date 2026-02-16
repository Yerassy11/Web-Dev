#include <bits/stdc++.h>
using namespace std;
string solution(int l,int r){
    for(int i=l;i<r;i++){
        array<bool,10>seen{};
        bool ok=true;
        string s=to_string(i);
        for (char c : s) {
            int d=c-'0';

            if (seen[d]){ 
                ok=false;
                break;
            }
            seen[d]=true;
    }
    if(ok) return s;
    }
    return "Understandable,have a great day";
}

int main(){
    int l,r;
    cin >> l >> r;
    cout << solution(l,r); 
}