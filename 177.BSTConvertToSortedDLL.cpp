// Approach 1 : Create a DLL using each element of the inorder traversal, Time : O(n), Space : O(n) + internal stack
// Approach 2 : While performing inorder traversal maintain the inorder predecessor node and for each node connect its left to the 
// predecessor node and connect the right of predecessor node to the current node. Time : O(n), Space : O(1) + internal stack

// --------->>> Approach 2 <<<-------------

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

void display(node* result) {
	node* curr = result;
	while(curr -> right != NULL) {
		cout << curr -> data << " ";
		curr = curr -> right;
	}
	cout << curr -> data << endl;
	while(curr -> left != NULL) {
		cout << curr -> data << " ";
		curr = curr -> left;
	}
	cout << curr -> data;
}

void inorder(node* root, node* &pred, node* &start) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left, pred, start);
	if(pred == NULL) {
		start = root;
		root -> left = NULL;
		pred = root;
	}
	else {
		pred -> right = root;
		root -> left = pred;
		pred = root;
	}
	inorder(root -> right, pred, start);
}

node* flatten(node* root) {
	node* pred = NULL;
	node* start = NULL;
	inorder(root, pred, start);
	return start;
}

int main() {
	node* root = new node(8);
	root -> left = new node(4);
	root -> left -> left = new node(2);
	root -> left -> left -> left = new node(1);
	root -> left -> left -> right = new node(3);
	root -> left -> right = new node(6);
	root -> left -> right -> left = new node(5);
	root -> left -> right -> right = new node(7);
	root -> right = new node(12);
	root -> right -> left = new node(10);
	root -> right -> left -> left = new node(9);
	root -> right -> left -> right = new node(11);
	root -> right -> right = new node(14);
	root -> right -> right -> left = new node(13);
	root -> right -> right -> right = new node(15);
	node* result = flatten(root);
	display(result);
	return 0;
}