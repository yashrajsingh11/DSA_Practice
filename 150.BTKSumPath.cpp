// Approach : We perform preorder traversal and for each element in traversal we find all the paths which can lead to k sum and print them.

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

void printVector(vector<struct node*> &v) {
	for(int i = 0; i < v.size(); i++) {
		cout << v[i] -> data << " ";
	}
	cout << endl;
}

void getSumPath(struct node* root, vector<struct node*> &v, int sum, int k) {
	if(root == NULL) {
		return;
	}
	v.push_back(root);
	sum = sum + root -> data;
	if(sum == k) {
		printVector(v);
	}
	getSumPath(root -> left, v, sum, k);
	getSumPath(root -> right, v, sum, k);
	v.pop_back();
}

void traverse(struct node* root, vector<struct node*> &v, int k) {
	if(root == NULL) {
		return;
	}
	getSumPath(root, v, 0, k);
	traverse(root -> left, v, k);
	traverse(root -> right, v, k);
}

void kSumPath(struct node* root, int k) {
	if(root == NULL) {
		return;
	}
	vector<struct node*> v;
	traverse(root, v, k);

}

int main() {
	struct node* root = new node(1);
	root -> left = new node(3);
	root -> left -> left = new node(2);
	root -> left -> right = new node(1);
	root -> left -> right -> left = new node(1);
	root -> right = new node(-1);
	root -> right -> left = new node(4);
	root -> right -> left -> left = new node(1);
	root -> right -> left -> right = new node(2);
	root -> right -> right = new node(5);
	root -> right -> right -> right = new node(6);
	int k = 5;
	kSumPath(root, k);
	return 0;
}