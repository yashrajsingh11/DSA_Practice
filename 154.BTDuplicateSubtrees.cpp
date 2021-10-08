// Approach : For each node in recursion, serialize its subtree by creating an inorder + preorder string of it. Check if the string is 
// not present in map then, add it and set count in map = 1. If it is present and count of string in map = 1 that means its duplicate is
// encountered for the first time, add root node to vector and increment count so that next time the string is encountered we know that
// it is already present in the vector.

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

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

void checkDuplicate(struct node* root, unordered_map<string, int> &mp, vector<struct node*> &result) {
    if(root == NULL) {
        return;
    }
    if(root -> left != NULL) {
        checkDuplicate(root -> left, mp, result);
    }
    if(root -> right != NULL) {
        checkDuplicate(root -> right, mp, result);
    }
    string temp = serialize(root);
    if(mp.find(temp) != mp.end()) {
        if(mp[temp] == 1) {
            result.push_back(root);
            mp[temp]++;
        }
    }
    else {
        mp[temp] = 1;
    }
}

vector<struct node*> printAllDups(struct node* root) {
    vector<struct node*> result;
    if(root == NULL) {
        return result;
    }
    unordered_map<string, int> mp;
    checkDuplicate(root, mp, result);
    return result;
}

void printInorder(struct node* root){
	if(root == NULL) {
		return;
	}
	printInorder(root -> left);
	cout << root -> data << " ";
	printInorder(root -> right);
}

int main() {
    struct node* root = new node(3);
    root -> left = new node(1);
    root -> right = new node(1);
    root -> left -> left = new node(2);
    root -> left -> left -> left = new node(4);
    root -> right -> left = new node(2); 
    root -> right -> left -> left = new node(4);
    vector<struct node*> result = printAllDups(root);
    for(int i = 0; i < result.size(); i++) {
    	printInorder(result[i]);
    	cout << endl;
    }
    return 0;
}