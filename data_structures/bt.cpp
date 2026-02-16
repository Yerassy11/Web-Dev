#include <bits/stdc++.h>
using namespace std;
struct Node{
    Node*left;
    Node*right;
    int value;
    int size;
    Node():value(0),left(nullptr),right(nullptr){};
    Node(int val):value(val),left(nullptr),right(nullptr){};
};
Node*add(Node*root,int v){
        if(root==nullptr){
            Node*new_n=new Node(v);
            root=new_n;
            return new_n;
        }
        if(v<root->value)
        root->left=add(root->left,root->value);
        else{
            root->right=add(root->right,v);
        }
        return root;
    }
Node*find(Node*root,int target){
    if(root==nullptr) return nullptr;

    if(root->value==target)
    return root;
    if(target<root->value)
        return find(root->left,target);
    else return find(root->right,target);
}
void inorder(Node* root) {
    if (root == nullptr) return;
    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}

// 🔹 Preorder (Корень → Левый → Правый)
void preorder(Node* root) {
    if (root == nullptr) return;
    cout << root->value << " ";
    preorder(root->left);
    preorder(root->right);
}

// 🔹 Postorder (Левый → Правый → Корень)
void postorder(Node* root) {
    if (root == nullptr) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->value << " ";
}

int size_subtree(Node*node){
    if(node==nullptr) return 0;

    return 1+size_subtree(node->left)+size_subtree(node->right);
}
void sum_of_lvl(Node*root){
    if(!root) return;
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        int size=q.size();
        int sum_lvl=0;
        for (int i=0;i<size;i++){
            Node*node=q.front();
            q.pop();
            sum_lvl+=node->value;
            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }
        cout << sum_lvl << " ";
    }
    
}


int main(){
    int n;
    cin >> n;

}