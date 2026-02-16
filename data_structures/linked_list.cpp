#include <bits/stdc++.h>
using namespace std;
struct Node{
    int value;
    Node*next;
    Node(int val):value(val),next(nullptr){};
};
struct  LinkedList{
    Node*head;
    Node*tail;
    int size;
    LinkedList():head(nullptr),tail(nullptr),size(0){};

    void print(){
        Node*curr=head;
        while(curr){
            cout << curr->value << ' ';
            curr=curr->next;
        }
    }
    void AddTail(int val){
        Node*new_node=new Node(val);
        size++;
        if(!tail){
            head=new_node;
            tail=new_node;
        }
        else{
            tail->next=new_node;
            tail=new_node;
        }
    }
    void AddHead(int val){
        Node*new_node=new Node(val);
        size++;
        if(!head){
            head=new_node;
            tail=new_node;
        }
        else{
            head->next=new_node;
            head=new_node;
        }
    }
    void pop_front(){
        if(head==nullptr){ cout << "ll in null";
        return;
        }    
        Node*curr=head;
        head=head->next;
        delete curr;

    }

    void pop_back(){
        if (head == nullptr) {
            cout << "List is empty!" << endl;
            return;
        }
        if (head->next == nullptr) { // если один элемент
            delete head;
            head = nullptr;
            return;
        }
        Node*curr=head;
        while(curr->next->next!=nullptr){
            curr=curr->next;

        }
        delete curr->next;
        curr->next=nullptr;

    }
     void insert_at(int index, int value) {
        if (index < 0) {
            cout << "Invalid index!" << endl;
            return;
        }

        if (index == 0) { // вставка в начало
            AddHead(value);
            return;
        }

        Node* temp = head;
        int currentIndex = 0;

        // идем до позиции index - 1
        while (temp != nullptr && currentIndex < index - 1) {
            temp = temp->next;
            currentIndex++;
        }

        if (temp == nullptr) {
            cout << "Index out of range!" << endl;
            return;
        }

        Node* newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
};


int main(){

}