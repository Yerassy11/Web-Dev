#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2; // чтобы избежать переполнения

        if (arr[mid] == target)
            return mid;               // нашли элемент, возвращаем индекс
        else if (arr[mid] < target)
            left = mid + 1;           // ищем справа
        else
            right = mid - 1;          // ищем слева
    }

    return -1; // если не нашли
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 11, 13};
    int x;
    cin >> x;

    int pos = binarySearch(a, x);

    if (pos != -1)
        cout << "Found in position " << pos << endl;
    else
        cout << "Not found" << endl;
}
