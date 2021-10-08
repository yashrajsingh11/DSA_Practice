// Approach : Taking one element from the given array at a time, construct a BST and return its inorder successor.

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

struct node* constructBST(struct node* root, int val) {
	if(root == NULL) {
		root = new node(val);
		return root;
	}
	if(root -> data > val) {
		root -> left = constructBST(root -> left, val);
	}
	else {
		root -> right = constructBST(root -> right, val);
	}
	return root;
}

void inSucc(struct node* root, int key, struct node* &succ, bool &check) {
	if(root == NULL) {
		return;
	}
	if(check == false) {
		return;
	}
	inSucc(root -> right, key, succ, check);
	if(key != root -> data and check == true) {
		succ = root;
	}
	if(key == root -> data) {
		check = false;
	}
	inSucc(root -> left, key, succ, check);
}

void replace(int* arr, int n) {
	struct node* root = NULL;
	for(int i = n - 1; i >= 0; i--) {
		root = constructBST(root, arr[i]);
		struct node* succ = NULL;
		bool check = true;
		inSucc(root, arr[i], succ, check);
		if(succ == NULL) {
			arr[i] = -1;
		}
		else {
			arr[i] = succ -> data;
		}
	}
}

int main() {
    int arr[] = {8, 58, 71, 18, 31, 32, 63, 92, 43, 3, 91, 93, 25, 80, 28};
    int n = sizeof(arr) / sizeof(arr[0]);
    replace(arr, n);
    for (int i = 0; i < n; i++) {
    	cout << arr[i] << " ";
    }
	return 0;
}