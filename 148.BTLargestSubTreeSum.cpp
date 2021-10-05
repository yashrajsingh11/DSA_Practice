// Approach : We recursively apply the post order traversal and for every node we return the sum of subtree till that node and if it is
// greater than the maximum sum till now then we update the maximum sum.

#include <iostream>
#include <climits>

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

int subTreeSum(struct node* root, int &maxSum) {
	if(root == NULL) {
		return 0;
	}
	int lSum = subTreeSum(root -> left, maxSum);
	int rSum = subTreeSum(root -> right, maxSum);
	maxSum = max(lSum + rSum + root -> data, maxSum);
	return lSum + rSum + root -> data;
}

int largestSumSubtree(struct node* root) {
	int maxSum = INT_MIN;
	subTreeSum(root, maxSum);
	return maxSum;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(-2);
	root -> left -> left = new node(4);
	root -> left -> right = new node(5);
	root -> right = new node(3);
	root -> right -> left = new node(-6);
	root -> right -> right = new node(2);
	cout << largestSumSubtree(root);
	return 0;
}