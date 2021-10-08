// Approach 1 : Take the nodes one by one from BST in inorder fashion and insert them into a self balancing BST(AVL Tree).
// Time : O(nlogn), Space : O(n)
// Approach 2 : Store the BST in an array and construct the BST taking the middle element as root node, the BST created will be balanced.
// Time : O(n), Space : O(n)

// ------->>> Approach 2 <<<---------

#include <iostream>
#include <vector>
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

void inorder(struct node* root, vector<int> &temp) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left, temp);
	temp.push_back(root -> data);
	inorder(root -> right, temp);
}

struct node* constructBBST(struct node* output, vector<int> &temp, int low, int high) {
	if(low > high) {
		return NULL;
	}
	int mid = (low + high)/2;
	if(output == NULL) {
		output = new node(temp[mid]);
	}
	output -> left = constructBBST(output -> left, temp, low, mid - 1);
	output -> right = constructBBST(output -> right, temp, mid + 1, high);
	return output;
}

struct node* getBBST(struct node* root) {
	vector<int> temp;
	inorder(root, temp);
	struct node* output = NULL;
	output = constructBBST(output, temp, 0, temp.size() - 1);
	return output;
}

void preorder(struct node* root) {
	if(root == NULL) {
		return;
	}
	cout << root -> data << " ";
	preorder(root -> left);
	preorder(root -> right);
}

int main() {
	struct node* root = new node(1);
	root -> right = new node(2);
	root -> right -> right = new node(3);
	root -> right -> right -> right = new node(4);
	root -> right -> right -> right -> right = new node(5);
	root -> right -> right -> right -> right -> right= new node(6);
	root -> right -> right -> right -> right -> right -> right= new node(7);
	root = getBBST(root);
	preorder(root);
	return 0;
}

