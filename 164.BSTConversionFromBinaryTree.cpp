// Approach : We store the inorder traversal of the given tree in a vector, then we sort it and generate a BST by simply adding the next
// element of the array to the right of the parent node and making the left ndode null.

#include <iostream>
#include <vector>
#include <algorithm>

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

void inorder(struct node* root, vector<int> &result) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left, result);
    result.push_back(root -> data);
    inorder(root -> right, result);
}

struct node* binaryTreeToBST (struct node* root) {
    vector<int> result;
    inorder(root, result);
    sort(result.begin(), result.end());
    struct node* output = new node(result[0]);
    struct node* temp = output;
    for(int i = 1; i < result.size(); i++) {
        temp -> left = NULL;
        temp -> right = new node(result[i]);
        temp = temp -> right;
    }
    return output;
}

void print(struct node* root) {
	if(root == NULL) {
		return;
	}
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
}

int main() {
	struct node* root = new node(3);
	root -> left = new node(2);
	root -> right = new node(1);
	root = binaryTreeToBST(root);
	print(root);
	return 0;
}