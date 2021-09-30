// Approach : We have a function which takes input a node and the current distance of the node from the root and returns the maximum
// distance from that node to the deepest node. We call the function recursively on left and right of that node therefore at each node we
// are getting the maximum depth we can reach from that node. At the end we get the maximum depth from the root which is the height.

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

int calcHeight(struct node* root, int height) {
	if(root == NULL) {
		return height;
	}
	int lheight = calcHeight(root -> left, height + 1);
	int rheight = calcHeight(root -> right, height + 1);
	return max(lheight, rheight);
}

int height(struct node* root){
	int result = calcHeight(root, 0);
	return result;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	// root -> right = new node(3);
	root -> left -> right = new node(4);
	root -> left -> right -> left = new node(4);
	cout << height(root);
	return 0;
}