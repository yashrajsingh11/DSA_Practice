// Approach : We find a node such that its value is lower than the maximum value among the two nodes and higher than the minimum value 
// among the two nodes.

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

struct node* calculateLCA(struct node* root, int low, int high) {
    if(root == NULL) {
        return NULL;
    }
    if(root -> data > high) {
        return calculateLCA(root -> left, low, high);
    }
    if(root -> data < low) {
        return calculateLCA(root -> right, low, high);
    }
    return root;
}

struct node* LCA(struct node* root, int n1, int n2) {
    if(n1 > n2) {
        return calculateLCA(root, n2, n1);
    }
    else {
        return calculateLCA(root, n1, n2);
    }
}

int main() {
	struct node* root = new node(8);
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
	cout << LCA(root, 13, 10) -> data;
	return 0;
}