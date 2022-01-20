// Approach : First pushback the head into vector, if it is the only element then return else, if left is not null we find the list of
// all the leftmost nodes. Then we print all the leaf nodes(remove the last leftmost node as it will be the first leaf node), now 
// recursively check if the node has no left and right node, then it is leaf node add it to vector. Then if the right is not null we find 
// the list of all the rightmost nodes (remove the last leaf node as it will be the first rightmost node).

#include <iostream>
#include <vector>

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

void printLeft(struct node* root, vector<int> &result) {
	if(root == NULL) {
		return;
	}
	result.push_back(root -> data);
	if(root -> left != NULL) {
		printLeft(root -> left, result);
	}
	else {
		printLeft(root -> right, result);
	}
}

void printNode(struct node* root, vector<int> &result) {
	if(root == NULL) {
		return;
	}
	if(root -> left == NULL and root -> right == NULL) {
		result.push_back(root -> data);
	}
	printNode(root -> left, result);
	printNode(root -> right, result);
}

void printRight(struct node* root, vector<int> &result) {
	if(root == NULL) {
		return;
	}
	if(root -> right != NULL) {
		printRight(root -> right, result);
	}
	else {
		printRight(root -> left, result);
	}
	result.push_back(root -> data);
}

vector<int> printBoundary(struct node *root) {
	vector<int> result;
	result.push_back(root -> data);
	if(root -> left == NULL and root -> right == NULL) {
		return result;
	}
	if(root -> left != NULL) {
		printLeft(root -> left, result);
		result.pop_back();
	}
	printNode(root, result);
	if(root -> right != NULL) {
		result.pop_back();
		printRight(root -> right, result);	
	}
	return result;
}

int main() {
	struct node* root = new node(1);
	// root -> left = new node(2);
	root -> right = new node(3);
	// root -> left -> left = new node(4);
	root -> right -> left = new node(5);
	root -> right -> right = new node(6);
	root -> right -> left -> left = new node(7);
	root -> right -> left -> right = new node(8);
	root -> right -> left -> left -> left = new node(9);
	vector<int> result = printBoundary(root);
	for(int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}
	return 0;
}
