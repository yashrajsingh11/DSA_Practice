// Approach : Perform inorder traversal until a value larger than key is not found, this value is the successor value. Perform reverse
// inorder traversal until a value smallet than key is not found, this value is the predecessor value.

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

void inorder(struct node* root, int key, bool &sucCheck, struct node* &suc) {
    if(root == NULL) {
        return;
    }
    inorder(root -> left, key, sucCheck, suc);
    if(root -> data > key and sucCheck == true) {
        suc = root;
        sucCheck = false;
        return;
    }
    inorder(root -> right, key, sucCheck, suc);
}

void reverseinorder(struct node* root, int key, bool &preCheck, struct node* &pre) {
    if(root == NULL) {
        return;
    }
    reverseinorder(root -> right, key, preCheck, pre);
    if(root -> data < key and preCheck == true) {
        pre = root;
        preCheck = false;
        return;
    }
    reverseinorder(root -> left, key, preCheck, pre);
}

void findPreSuc(struct node* root, struct node*& pre, struct node*& suc, int key) {
    bool sucCheck = true;
    bool preCheck = true;
    inorder(root, key, sucCheck, suc);
    reverseinorder(root, key, preCheck, pre);
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
	
	int key = 5;
	struct node* pre = NULL;
	struct node* suc = NULL;
	findPreSuc(root, pre, suc, key);
	if(pre == NULL) {
		cout << -1 << " ";
	}
	else {
		cout << pre -> data << " ";
	}
	if(suc == NULL) {
		cout << -1 << " ";
	}
	else {
		cout << suc -> data << " ";
	}
	return 0;
}