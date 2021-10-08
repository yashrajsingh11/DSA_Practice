// Approach : We can perform inorder traversal and check if the previous element is smaller than the current element, if it is not then
// it is not a BST.

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

void inorder(struct node* root, bool &check, struct node* &pre) {
    if(root == NULL) {
        return;
    }
    if(check == false) {
        return;
    }
    
    inorder(root -> left, check, pre);
    if(pre != NULL) {
        if(pre -> data >= root -> data) {
            check = false;
        }
    }
    pre = root;
    inorder(root -> right, check, pre);
}

bool isBST(struct node* root) {
    bool check = true;
    if(root == NULL) {
        return check;
    }
    struct node* pre = NULL;
    inorder(root, check, pre);
    return check;
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
	cout << isBST(root);
	return 0;
}