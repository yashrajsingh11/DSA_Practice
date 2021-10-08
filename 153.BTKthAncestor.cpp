// Approach : While performing preorder traversal, we keep checking if we have found the node whose kth ancestor we have to find. If it 
// is found we decrement k by 1 and return the node. Now we postordely check, if the node whose ancestor we have to find, is in the 
// current subtree. If it is then we decrement k, if not we go upwards in the recursion. If k is zero, then the current node is the kth 
// ancestor, then we decrement k again so that the ancestor value is never changed again in the recursion. If the ancestor does not 
// exist then the recursion will return the value of the node whose ancestor we have to find, so at end we can check if the value returned
// is same as the node we wanted to check for then we print -1 else we print the data of the node returned.

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

struct node* kthAncestor(struct node* root, int n, int &k) {
	if(root == NULL) {
		return NULL;
	}
	if(root -> data == n) {
		k = k - 1;
		return root;
	}
	struct node* lnode = kthAncestor(root -> left, n, k);
	struct node* rnode = kthAncestor(root -> right, n, k);

	if(lnode != NULL or rnode != NULL) {
		if(k == 0) {
			k = k - 1; 
			return root;
		}
		k = k - 1;
	}
	if(lnode != NULL) {
		return lnode;
	}
	return rnode;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> right  -> left = new node(4);
	root -> right  -> right = new node(5);
	root -> right -> left -> left = new node(6);
	root -> right  -> right -> left = new node(7);
	int n = 6;
	int k = 1;
	struct node* result = kthAncestor(root, n, k);
	if(result -> data == n) {
		cout << -1;
	}
	else {
		cout << result -> data;
	}
}