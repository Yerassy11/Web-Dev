#include <bits/stdc++.h>
using namespace std;

// Алгоритм Рабина–Карпа для поиска всех вхождений pattern в text
vector<int> rabinKarp(const string& text, const string& pattern) {
    int n = text.size();
    int m = pattern.size();
    if (m > n) return {};

    const long long P = 257;           // база (должна быть > max ASCII)
    const long long MOD = 1000000007;  // большое простое число

    long long hash_pattern = 0; // хеш шаблона
    long long hash_window = 0;  // хеш текущего окна в тексте

    long long power = 1; // P^(m-1) mod MOD — нужно для удаления старшего символа

    // Вычисляем P^(m-1)
    for (int i = 1; i < m; i++)
        power = (power * P) % MOD;

    // Считаем хеш pattern и первых m символов текста
    for (int i = 0; i < m; i++) {
        hash_pattern = (hash_pattern * P + (unsigned char)pattern[i]) % MOD;
        hash_window  = (hash_window  * P + (unsigned char)text[i]) % MOD;
    }

    vector<int> occurrences;

    // Проходим по всем окнам текста длины m
    for (int i = 0; i <= n - m; i++) {

        // Если хеши совпали — проверяем реальные символы (от коллизий)
        if (hash_window == hash_pattern) {
            if (text.compare(i, m, pattern) == 0) {
                occurrences.push_back(i);
            }
        }

        // Сдвигаем окно вправо (кроме последнего)
        if (i < n - m) {
            // Удаляем вклад text[i] и добавляем text[i+m]
            hash_window = (hash_window - (unsigned char)text[i] * power) % MOD;
            if (hash_window < 0) hash_window += MOD;

            hash_window = (hash_window * P + (unsigned char)text[i + m]) % MOD;
        }
    }

    return occurrences;
}

int main() {
    string text = "abracadabra";
    string pattern = "abra";

    vector<int> pos = rabinKarp(text, pattern);

    cout << "found occ: " << pos.size() << "\n Positions:\n";
    for (int p : pos)
        cout << p << " ";  // позиции 0-based

    return 0;
}
