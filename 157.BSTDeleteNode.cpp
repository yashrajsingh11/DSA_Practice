// Approach : We search for the node to be deleted in the BST, if it is found then we remove the left subtree of the node and connect it
// to the leftmost node in the right subtree, since according to the rules of a BST the left subtree must have smaller values than right
// subtree and the smallest value larger than the largest value in the left subtree of the deleted node is present in the leftmost node 
// of the right subtree, vice versa is also true. 

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

void connect(struct node* rChild, struct node* lChild) {
    if(rChild -> left == NULL) {
        rChild -> left = lChild;
        return;
    }
    connect(rChild -> left, lChild);
}
struct node* deleteNode(struct node* root, int key) {
    if(root == NULL) {
        return NULL;
    }

    if(root -> data == key) {
        if(root -> right == NULL and root -> left == NULL) {
            return NULL;
        }
        if(root -> right == NULL and root -> left != NULL) {
            return root -> left;
        }
        if(root -> right != NULL and root -> left == NULL) {
            return root -> right;
        }
        connect(root -> right, root -> left);
        root -> left = NULL;
        return root -> right;
    }

    if(root -> data > key) {
        root -> left = deleteNode(root -> left, key);
    }
    else {
        root -> right = deleteNode(root -> right, key);
    }
    return root;
}

void inorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left);
	cout  << root -> data << " ";
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
	root = deleteNode(root, 7);
	inorder(root);
	return 0;
}