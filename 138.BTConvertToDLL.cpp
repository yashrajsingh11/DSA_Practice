// Approach : Perform inorder traversal. If it is the first node then assign it to the head of the dll, and asisgn prev to it.
// For the remaining nodes in inorder traversal assign there left to the prev and assign prev right to node, while updating prev.
// We can either pass a variable by refernce at the start of recursion or declare a static variable which will update itself instead of
// creating a new variable for each recursive step.


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

void display(struct node* head) {
	struct node* ptr = head;
	while(ptr -> right != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> right;
	}
	cout << ptr -> data << " ";
	cout << endl;
	while(ptr -> left != NULL) {
		cout << ptr -> data << " ";
		ptr = ptr -> left;
	}
	cout << ptr -> data << " ";
}

void inorder(struct node* root, struct node** head, struct node** prev) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left, head, prev);
	if(*prev == NULL) {
		*head = root;
	}
	else {
		root -> left = *prev;
		(*prev) -> right = root;
	}
	*prev = root;
	inorder(root -> right, head, prev);
}

struct node* bToDLL(struct node* root) {
	struct node* head = NULL;
	struct node* prev = NULL;
	inorder(root, &head, &prev);
	return head;
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
	struct node* head = bToDLL(root);
	display(head);
	return 0;
}