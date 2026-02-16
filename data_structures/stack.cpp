#include <bits/stdc++.h>
using namespace std;

class Stack {

    int* arr;      // массив для хранения данных
    int capacity;  // максимальный размер
    int topIndex;  // индекс вершины стека
public:
    // Конструктор
    Stack(int size) {
        capacity = size;
        arr = new int[capacity];
        topIndex = -1; // -1 значит стек пуст
    }

    // Деструктор
    ~Stack() {
        delete[] arr;
    }

    // Добавить элемент
    void push(int x) {
        if (topIndex == capacity - 1) {
            cout << "Стек переполнен!\n";
            return;
        }
        arr[++topIndex] = x;
    }

    // Удалить верхний элемент
    void pop() {
        if (empty()) {
            cout << "Стек пуст!\n";
            return;
        }
        topIndex--;
    }

    // Посмотреть верхний элемент
    int top() {
        if (empty()) {
            cout << "Стек пуст!\n";
            return -1;
        }
        return arr[topIndex];
    }

    // Проверка на пустоту
    bool empty() {
        return topIndex == -1;
    }

    // Размер стека
    int size() {
        return topIndex + 1;
    }
};

int main() {
    Stack st(5);
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Вершина стека: " << st.top() << "\n"; // 30
    st.pop();
    cout << "После pop вершина: " << st.top() << "\n"; // 20
    cout << "Размер: " << st.size() << "\n"; // 2
    return 0;
}
