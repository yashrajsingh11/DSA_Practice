// Approach : Recursively calculate the sum of left subtree and right sub tree and update the current nodes data, but while returning
// also add the current nodes previous data to the sum which is passed to the upper level of the tree.

#include <iostream>

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

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout << root -> data << " ";
	inorder(root -> right);
}

int calcSum(struct node* root) {
	if(root == NULL) {
		return 0;
	}
	int lsum = calcSum(root -> left);
	int rsum = calcSum(root -> right);
	int temp = root -> data;
	root -> data = lsum + rsum;
	return temp + root -> data;
}

void toSumTree(struct node* root) {
	if(root == NULL) {
		return;
	}
	calcSum(root);
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> right -> left = new node(5);
	root -> right -> right = new node(6);
	root -> right -> left -> left = new node(7);
	root -> right -> left -> right = new node(8);
	toSumTree(root);
	inorder(root);
	return 0;
}