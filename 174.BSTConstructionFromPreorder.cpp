// Approach : Take each element of preorder array and insert it into a binary tree.

#include <iostream>

using namespace std;

struct node{
    int data;
    struct node* left;
    struct node* right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

node* constructBST(node* root, int val) {
    if(root == NULL) {
        root = new node(val);
        return root;
    }
    if(root -> data > val) {
        root -> left = constructBST(root -> left, val);
    }
    else {
        root -> right = constructBST(root -> right, val);
    }
    return root;
}

node* post_order(int pre[], int size) {
    node* root = NULL;
    for(int i = 0; i < size; i++) {
        root = constructBST(root, pre[i]);
    }
    return root;
}

void postOrder(node* root) {
    if(root == NULL) {
        return;
    }
    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int main() {
    int pre[] = {40, 30, 32, 35, 80, 90, 100, 120};
    int n = sizeof(pre)/sizeof(pre[0]);
    node* root = post_order(pre, n);
    postOrder(root);
}