#include <bits/stdc++.h>
using namespace std;

int main() {
    priority_queue<int> pq; // по умолчанию max-heap


    pq.push(10) ;
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Элементы по приоритету:\n";
    while (!pq.empty()) {
        cout << pq.top() << " "; // всегда выводит наибольший элемент
        pq.pop();
    }
    //-----------------------------------------------MIN-HEAP
    priority_queue<int, vector<int>, greater<int>> pq; // min-heap

    pq.push(10);
    pq.push(5);
    pq.push(20);
    pq.push(15);

    cout << "Min-heap порядок:\n";
    while (!pq.empty()) {
        cout << pq.top() << " "; // всегда минимальный элемент
        pq.pop();
    }

}

