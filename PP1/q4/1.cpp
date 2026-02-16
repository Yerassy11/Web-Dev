#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    map<string, int> mp;

    while (cin >> s) {
        mp[s]++;
    }

    vector<pair<string, int>> v(mp.begin(), mp.end());

    sort(v.begin(), v.end(), [](const auto& a, const auto& b) {
        if (a.second != b.second)
            return a.second > b.second;   // по убыванию частоты
        return a.first < b.first;         // по алфавиту
    });

    for (const auto& [w, n] : v) {
        cout << w << " : " << n << endl;
    }

    return 0;
}
