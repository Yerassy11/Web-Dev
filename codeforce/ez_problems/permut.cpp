#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >>n;
    deque<int>dq;
    for(int i=1;i<=n;i++){
        dq.push_back(i);
    }
    while(n--){
        dq.push_back(dq.front());
        dq.pop_front();
        for(auto x:dq){
            cout << x;
        }
        cout << endl;
    }


}