#include <vector>
using namespace std;

vector<int> restoreOrder(const vector<int>& a) {
    int n = a.size();
    vector<int> result(n, -1);

    for (int i = 0; i < n; i++) {
        int pos = a[i];  

        if (pos < 0 || pos >= n) {
            return {};
        }

        if (result[pos] != -1) {
            return {};
        }

        result[pos] = i + 1; 
    }

    return result;
}
