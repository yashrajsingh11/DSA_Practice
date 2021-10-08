// Approach : Perform Reverse Inorder Traversal until the kth node is found. This is the kth largest node of the BST.

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

void reverseInorder(struct node* root, int &K, int &result) {
    if(root == NULL) {
        return;
    }
    if(K < 0) {
        return;
    }
    reverseInorder(root -> right, K, result);
    K--;
    if(K == 0) {
        result = root -> data;
        K--;
    }
    reverseInorder(root -> left, K, result);
}

int kthLargest(struct node *root, int K) {
    int result;
    reverseInorder(root, K, result);
    return result;
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
	cout << kthLargest(root, 9);
	return 0;
}