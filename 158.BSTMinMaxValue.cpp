// Approach : The leftmost node of a BST has the minimum value and the rightmost node has the maximum value

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

int minValue(struct node* root) {
    if(root -> left == NULL) {
        return root -> data;
    }
    return minValue(root -> left);
}

int maxValue(struct node* root) {
    if(root -> right == NULL) {
        return root -> data;
    }
    return maxValue(root -> right);
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
	cout << minValue(root) << endl;
	cout << maxValue(root) << endl;
	return 0;
}