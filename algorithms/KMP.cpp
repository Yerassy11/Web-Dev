#include <bits/stdc++.h>
using namespace std;

//Функция для вычисления префикс-функции (π-массив)
vector<int> prefix_function(const string &pattern) {
    int n = pattern.size();
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i - 1];
        while (j > 0 && pattern[i] != pattern[j])
            j = pi[j - 1];
        if (pattern[i] == pattern[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

// Функция поиска KMP
vector<int> KMP(const string &text, const string &pattern) {
    vector<int> pi = prefix_function(pattern);
    vector<int> result;
    int j = 0; // позиция в pattern

    for (int i = 0; i < text.size(); i++) {
        while (j > 0 && text[i] != pattern[j])
            j = pi[j - 1];

        if (text[i] == pattern[j])
            j++;

        if (j == pattern.size()) {
            result.push_back(i - j + 1); // нашли вхождение
            j = pi[j - 1];
        }
    }
    return result;
}

int main() {
    string text, pattern;
    cin >> text >> pattern;

    vector<int> matches = KMP(text, pattern);

    if (matches.empty()) cout << "Подстрока не найдена\n";
    else {
        cout << "Найдена на позициях: ";
        for (int pos : matches) cout << pos << " ";
        cout << "\n";
    }
}
