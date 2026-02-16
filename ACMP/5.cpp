#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int>fours,trees;
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x%2==0){
            fours.push_back(x);
        }
        else trees.push_back(x);
    }
    for(int i=0;i<trees.size();i++){
        cout << trees[i] << " ";
    }
    cout << endl;
    for(int i=0;i<fours.size();i++){
        cout << fours[i] << " ";
    }
    cout << endl;
    if(fours.size()>=trees.size()) cout << "YES";
    else cout << "NO";
    return 0;
}