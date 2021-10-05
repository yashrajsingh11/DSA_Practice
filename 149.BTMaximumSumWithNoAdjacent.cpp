// Approach : For each node the maximum sum we can get can be either from the root node and the grandchildren nodes or the sum of the 
// maximum sum we can get from each child node. We find the grandchildren sum in preorder traversal and then we find the child sum in
// post order traversal and return the maximum of both. We can use a map for faster calculation of child sum by sstoring the maximum
// value we are getting for each node.

#include <iostream>
#include <map>

using namespace std;

struct node {
	int data;
	struct node* left;
	struct node* right;

	node(int x){
		data = x;
		left = NULL;
		right = NULL;
	}
};

int includedSum(struct node* root) {
	if(root == NULL) {
		return 0;
	}
	int sum = 0;
	if(root -> left != NULL) {
		sum = sum + includedSum(root -> left -> left);
		sum = sum + includedSum(root -> left -> right);
	}
	if(root -> right != NULL) {
		sum = sum + includedSum(root -> right -> left);
		sum = sum + includedSum(root -> right -> right);
	}
	return root -> data + sum;
}

int calcMaxSum(struct node* root, map<struct node*, int> &m) {
	if(root == NULL) {
		return 0;
	}
	if(m.find(root) != m.end()) {
		return m[root];
	}
	int included = includedSum(root);
	int excluded = calcMaxSum(root -> left, m) + calcMaxSum(root -> right, m);
	m[root] = max(included, excluded);
	return m[root];
}

int getMaxSum(struct node* root) {
	if(root == NULL) {
		return 0;
	}
	map<struct node*, int> m;
	return calcMaxSum(root, m);
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(1);
	root -> right -> left = new node(4);
	root -> right -> right = new node(5);
	root -> right -> left -> left = new node(2);
	root -> right -> left -> right = new node(1);
	root -> right -> right -> left = new node(2);
	root -> right -> right -> right = new node(2);
	cout << getMaxSum(root);
	return 0;
}