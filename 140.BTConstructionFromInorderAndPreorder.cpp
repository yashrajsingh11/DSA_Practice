// Approach : We call a function recursively in which we take one preorder array element at a time and we find its index in inorder array. 
// All the element to the left of that index belong to left subtree of that node and all the element to the right of that index belong 
// to the right subtree of that node. We pass the starting and ending of those subarrays to the function called for the left and right 
// of the root. If the starting and ending index is same then it is a leaf, if starting is greater that means we reached the bottom of
// that subtree.  

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

void postorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	postorder(root -> left);
	postorder(root -> right);
	cout << root -> data << " ";
}

struct node* build(int* in, int* pre, int start, int end, int &preIndex) {
	if(start > end) {
		return NULL;
	}
	struct node* root = new node(pre[preIndex]);
	preIndex++;
	if(start == end) {
		return root;
	}
	int inIndex = start;
	while(root -> data != in[inIndex] and inIndex < end) {
		inIndex++;
	}
	root -> left = build(in, pre, start, inIndex - 1, preIndex);
	root -> right = build(in, pre, inIndex + 1, end, preIndex);
	return root;
}

struct node* buildTree(int in[],int pre[], int n) {
	if(n == 0) {
		return NULL;
	}
	int preIndex = 0;
	struct node* root = build(in, pre, 0, n - 1, preIndex);
	return root;
}

int main() {
	int in[] = {3, 1, 4, 0, 5, 2};
	int pre[] = {0, 1, 3, 4, 2, 5};
	int n = 6;
	struct node* root = buildTree(in, pre, n);
	postorder(root);
	return 0;
}