// Approach 1 : Store the inorder traversal of both BST in arrays, merge those sorted arrays and construct BST taking root from centre.
// Time : O(m+n), Space : O(m+n)

// Approach 2 : Consider one of the BST to be a self balancing BST(AVL Tree) and insert the nodes from the other BST into this BST.
// Time : O(mlogn), Space : O(1)

// Approach 3 : Convert both BST to DLL, sort them, merge them, construct a balanced BST from them.(Every operation can be inplace)
// https://www.geeksforgeeks.org/convert-a-binary-tree-to-a-circular-doubly-link-list/ 
// https://www.geeksforgeeks.org/in-place-conversion-of-sorted-dll-to-balanced-bst/
// Time : O(m + n), Space : O(1)

// ------->>> Approach 1 <<<--------

#include <iostream>
#include <vector>

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

void inorder(struct node* root, vector<int> &BST) {
	if(root == NULL) {
		return;
	}
	inorder(root -> left, BST);
	BST.push_back(root -> data);
	inorder(root -> right, BST);
}

void merge(vector<int> &BST1, vector<int> &BST2, vector<int> &BBST) {
	int i = 0, j = 0;
	while(i < BST1.size() and j < BST2.size()) {
		if(BST1[i] < BST2[j]) {
			BBST.push_back(BST1[i]);
			i++;
		}
		else {
			BBST.push_back(BST2[j]);
			j++;
		}
	}
	while(i < BST1.size()) {
		BBST.push_back(BST1[i]);
		i++;
	}
	while(j < BST2.size()) {
		BBST.push_back(BST2[j]);
		j++;
	}
}

struct node* constructBBST(struct node* output, vector<int> & BBST, int low, int high) {
	if(low > high) {
		return NULL;
	}
	int mid = (low + high) / 2;
	if(output == NULL) {
		output = new node(BBST[mid]);
	}
	output -> left = constructBBST(output -> left, BBST, low, mid - 1);
	output -> right = constructBBST(output -> right, BBST, mid + 1, high);
	return output;
}

struct node* mergeBST(struct node* root1, struct node* root2) {
	vector<int> BST1;
	vector<int> BST2;
	vector<int> BBST;
	inorder(root1, BST1);
	inorder(root2, BST2);
	merge(BST1, BST2, BBST);
	struct node* output = NULL;
	output = constructBBST(output, BBST, 0, BBST.size() - 1);
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

void print(struct node* root) {
	if(root == NULL) {
		return;
	}
	print(root -> left);
	cout << root -> data << " ";
	print(root -> right);
}

int main() {
	struct node* root1 = new node(5);
	root1 -> left = new node(3);
	root1 -> left -> left = new node(1);
	root1 -> right = new node(7);
	root1 -> right -> right = new node(9); 
	struct node* root2 = new node(6);
	root2 -> left = new node(4);
	root2 -> left -> left = new node(2);
	root2 -> right = new node(8);
	root2 -> right -> right = new node(10);
	struct node* result = mergeBST(root1, root2);
	preorder(result);
	cout << endl;
	print(result); 
	return 0;
}