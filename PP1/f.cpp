#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string, int> mp;

    while (cin >> s) {
        mp[s]++;
    }

    for (const auto& [w, n] : mp) {
        cout << w << " : " << n << endl;
    }
    return 0;
}
