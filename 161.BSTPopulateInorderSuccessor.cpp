// Approach : We traverse the BST in reverse inorder fashion and for each node we keep track of the previous node in the recursion which 
// is assigned to the next of the current node since it is the inorder successor of the current node.

#include <iostream>

using namespace std;

struct node{
	int data;
	struct node* left;
	struct node* right;
	struct node* next;

	node(int x) {
		data = x;
		left = NULL;
		right = NULL;
		next = NULL;
	}
};

void reverseInorder(struct node* root, struct node* &suc) {
    if(root == NULL) {
        return;
    }
    reverseInorder(root -> right, suc);
    if(suc != NULL) {
        root -> next = suc;
    }
    suc = root;
    reverseInorder(root -> left, suc);
}

void populateNext(struct node *root) {
    struct node* suc = NULL;
    reverseInorder(root, suc);
}

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	if(root -> next != NULL) {
		cout << root -> data << " -> " << root -> next -> data << endl;		
	}
	else {
		cout << root -> data << " -> " << -1 << endl;
	}
	inorder(root -> right);
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
	
	populateNext(root);
	inorder(root);
	return 0;
}