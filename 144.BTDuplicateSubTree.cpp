// Approach : We recursively reach every element which is not the leaf node. Then we serialise the tree taking that node as root. 
// Serialized tree is a string of inorder and preorder traveral from that node. We have an unordered set which stores the serialized tree.
// For every serialized tree if it is not present in the set then we add it and continue and if it is present then duplicate is present. 

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

struct node {
    int data;
    struct node* left;
    struct node* right;

    node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

void inorder(struct node* root, string &result) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left, result);
    result.push_back(root -> data);
    inorder(root -> right, result);
}

void preorder(struct node* root, string &result) {
    if(root == NULL) {
        return;
    }
    result.push_back(root -> data);
    preorder(root -> left, result);
    preorder(root -> right, result);
}

string serialize(struct node* root) {
    string result = "";
    inorder(root, result);
    preorder(root, result);
    return result;
}

void checkDuplicate(struct node* root, int &globalCheck, unordered_set<string> &s) {
    if(globalCheck == 1) {
        return;
    }
    if(root -> left == NULL and root -> right == NULL) {
        return;
    }
    if(root -> left != NULL) {
        checkDuplicate(root -> left, globalCheck, s);
    }
    if(root -> right != NULL) {
        checkDuplicate(root -> right, globalCheck, s);
    }
    string temp = serialize(root);
    if(s.find(temp) != s.end()) {
        globalCheck = 1;
    }
    else {
        s.insert(temp);
    }
}

int dupSub(struct node* root) {
    if(root == NULL) {
        return 0;
    }
    int globalCheck = 0;
    unordered_set<string> s;
    checkDuplicate(root, globalCheck, s);
    return globalCheck;
}

int main() {
    struct node* root = new node(1);
    root -> left = new node(2);
    root -> right = new node(3);
    root -> left -> left = new node(1);
    root -> left -> left -> left= new node(2);
    root -> left -> left -> right= new node(3);
    root -> right -> left = new node(1);
    root -> right -> left -> left = new node(2);
    root -> right -> left -> right = new node(3);
    cout << dupSub(root);
    return 0;
}