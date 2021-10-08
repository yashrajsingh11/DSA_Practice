// Approach : Since the smaller nodes are to the left and larger nodes are to the right in a BST. Hence we need to search in only those
// subtrees where the node can exist. For insertion we need to find the subtree where the node can exist and insert it.

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

struct node* search(struct node* root, int key) {
	if(root == NULL or root -> data == key) {
		return root;
	}
	if(root -> data > key) {
		return search(root -> left, key);
	}
	return search(root -> right, key);
}

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

struct node* insert(struct node* root, int val) {
	if(root == NULL) {
		struct node* temp = new node(val);
		return temp;
	}
	if(root -> data == val) {
		cout << "Node Exists" << endl;
		return root;
	}
	if(root -> data > val) {
		root -> left = insert(root -> left, val);
	}
	else {
		root -> right = insert(root -> right, val);
	}
	return root;
}

int main() {
	struct node* root = new node(8);
	root -> left = new node(3);
	root -> left -> left = new node(1);
	root -> left -> right = new node(6);
	root -> left -> right -> left = new node(4);
	root -> left -> right -> right= new node(7);
	root -> right = new node(10);
	root -> right -> right = new node(14);
	root -> right -> right -> left = new node(13);
	cout << search(root, 6) -> data << endl;
	insert(root,5);
	inorder(root);
}