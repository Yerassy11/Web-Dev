#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;       // значение узла
    Node* next;     // ссылка на следующий элемент
};

struct Queue {
    Node* front;    // начало очереди
    Node* back;     // конец очереди
    int size;       // количество элементов

    Queue() {
        front = nullptr;
        back = nullptr;
        size = 0;
    }

    // добавить элемент в конец
    void push(int x) {
        Node* newNode = new Node();
        newNode->data = x;
        newNode->next = nullptr;

        if (back == nullptr) { // если очередь пустая
            front = back = newNode;
        } else {
            back->next = newNode;
            back = newNode;
        }
        size++;
    }

    // удалить элемент с начала
    void pop() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return;
        }
        Node* temp = front;
        front = front->next;
        if (front == nullptr) back = nullptr; // если очередь опустела
        delete temp;
        size--;
    }

    // вернуть первый элемент
    int first() {
        if (front == nullptr) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return front->data;
    }

    // вернуть последний элемент
    int last() {
        if (back == nullptr) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return back->data;
    }

    // проверить, пуста ли очередь
    bool empty() {
        return front == nullptr;
    }

    // вернуть размер
    int get_size() {
        return size;
    }
};
