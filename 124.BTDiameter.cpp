// Approach 1 : We have a recursive function which takes computes the diameter of its left subtree and right subtree and a recursive function
// which computes the height of left and right subtree. diameter of the tree including itself will be leftHeight + rightHeight + 1;
// compare the 3 diameters and return the maximum. At the end we will have the maximum diameter of the tree. O(n^2) time.

// Approach 2 : We have a recursive function which calculates the diameter for each node, which is leftHeight + rightHeight + 1
// we compare for maximum while returning the height of the tree upto that node which is max(leftheight, rightheight) + 1; O(n) time.

// ------>>> Approach 2 <<<------

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

int calcDiameter(struct node* root, int &ans) {
	if(root == NULL) {
		return 0;
	}
	int lheight = calcDiameter(root -> left, ans);
	int rheight = calcDiameter(root -> right, ans);
	ans = max(ans, lheight + rheight + 1);
	return 1 + max(lheight, rheight);
}

int diameter(struct node* root) {
	if(root == NULL) {
		return 0;
	}     
	int ans = 0;
	int result = calcDiameter(root, ans);
	return ans;
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> left -> left = new node(3);
	root -> left -> right = new node(4);
	root -> left -> right ->left = new node(5);
	root -> left -> right -> right = new node(6);
	root -> right = new node(7);
	root -> right -> right = new node(8);
	root -> right -> right -> right = new node(9);
	root -> right -> right -> right -> right = new node(10);
	root -> right -> right -> right -> left = new node(11);
	root -> right -> right -> right -> left -> right = new node(12);
	root -> right -> right -> right -> left -> left = new node(13);
	cout << diameter(root);
	return 0;
}

// ------>>> Approach 1 <<<------

// #include <iostream>
// #include <algorithm>

// using namespace std;

// struct node {
// 	int data;
// 	struct node* left;
// 	struct node* right;

// 	node(int x) {
// 		data = x;
// 		left = NULL;
// 		right = NULL;
// 	}
// };

// int calcHeight(struct node* root, int height) {
// 	if(root == NULL) {
// 		return height;
// 	}
// 	int lheight = calcHeight(root -> left, height + 1);
// 	int rheight = calcHeight(root -> right, height + 1);
// 	return max(lheight, rheight);
// }

// int calcDiameter(struct node* root) {
// 	if(root == NULL) {
// 		return 0;
// 	}
// 	int leftDiameter = calcDiameter(root -> left);
// 	int rightDiameter = calcDiameter(root -> right);
// 	int leftHeight = calcHeight(root -> left, 0);
// 	int rightHeight = calcHeight(root -> right, 0);
// 	int centerDiameter = leftHeight + rightHeight + 1;
// 	return max(max(leftDiameter, rightDiameter), centerDiameter);
// }

// int diameter(struct node* root) {
// 	if(root == NULL) {
// 		return 0;
// 	}     
// 	int result = calcDiameter(root);
// 	return result;
// }

// int main() {
// 	struct node* root = new node(1);
// 	root -> left = new node(2);
// 	root -> left -> left = new node(3);
// 	root -> left -> right = new node(4);
// 	root -> left -> right ->left = new node(5);
// 	root -> left -> right -> right = new node(6);
// 	root -> right = new node(7);
// 	root -> right -> right = new node(8);
// 	root -> right -> right -> right = new node(9);
// 	root -> right -> right -> right -> right = new node(10);
// 	root -> right -> right -> right -> left = new node(11);
// 	// root -> right -> right -> right -> left -> right = new node(12);
// 	// root -> right -> right -> right -> left -> left = new node(13);
// 	cout << diameter(root);
// 	return 0;
// }
