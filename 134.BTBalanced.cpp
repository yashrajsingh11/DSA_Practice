// Approach : Maintain a boolean check which becomes false when the tree is not balanced and we do not perform any calculation further.
// For each recursion we return the height of the tree as max(lheight, rheight) + 1 which serves as either lheight or rheight depending
// on the recursion we are on. We also track the check by comparing the difference of lheight and rheight. 

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

int checkBalanced(struct node* root, bool &check) {
	if(root == NULL) {
		return 0;
	}
	int lheight = checkBalanced(root -> left, check);
	int rheight = checkBalanced(root -> right, check);
	if(check == false) {
		return -1;
	}
	if(abs(lheight - rheight) > 1) {
		check = false;
	}
	return 1 + max(lheight, rheight);
}

bool isBalanced(struct node* root) {
	if(root == NULL) {
		return 0;
	}     
	bool check = true;
	int result = checkBalanced(root, check);
	return check;
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
	root -> right -> left -> left -> right = new node(9);
	cout << isBalanced(root);
	return 0;
}