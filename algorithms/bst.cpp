#include <bits/stdc++.h>
using namespace std;
struct Node
{
    Node*left;
    Node*right;
    int value;
    Node(int val):value(val),left(nullptr),right(nullptr){};
};
Node*insert(Node*root,int val){
    if(root==nullptr)
        return new Node(val);
    
    if(val>root->value){
        root->right=insert(root->right,val);
    }
    else if(val<root->value){
        root->left=insert(root->left,val);
    }
    return root;

        
}
bool search(Node*root,int target){
    if(root==nullptr) return false;

    if(root->value==target) return true;
    else if(target<root->value){
        return search(root->left,target);
    }
    else return search(root->right,target);

}   
void inorder(Node*root){
    if(root=nullptr) return;

    inorder(root->left);
    cout << root->value << " ";
    inorder(root->right);
}
