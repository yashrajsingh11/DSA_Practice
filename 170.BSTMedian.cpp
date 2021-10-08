// Approach : Perform Morris Traversal to get the size of the BST, then calculate the nodes we need to find to get the median and perform
// morris traversal again to reach that node.

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

struct node* predecessor(struct node* root) {
	struct node* curr = root -> left;
	while(curr -> right != NULL and curr -> right != root) {
		curr = curr -> right;
	}
	return curr;
}

int count(struct node* root) {
	int n = 0;
	struct node* curr = root;
	while(curr != NULL) {
		if(curr -> left == NULL) {
			n++;
			curr = curr -> right;
		}
		else {
			struct node* pred = predecessor(curr);
			if(pred -> right == NULL) {
				pred -> right = curr;
				curr = curr -> left;
			}
			else {
				n++;
				pred -> right = NULL;
				curr = curr -> right;
			}
		}
	}
	return n;
}

int getNode(struct node* root, int key) {
	struct node* curr = root;
	struct node* result = NULL;
	while(curr != NULL) {
		if(curr -> left == NULL) {
			key--;
			if(key == 0) {
				result = curr;
				key--;
			}
			curr = curr -> right;
		}
		else {
			struct node* pred = predecessor(curr);
			if(pred -> right == NULL) {
				pred -> right = curr;
				curr = curr -> left;
			}
			else {
				key--;
				if(key == 0) {
					result = curr;
					key--;
				}
				pred -> right = NULL;
				curr = curr -> right;
			}
		}
	}
	if(result == NULL) {
		return -1;
	}
	return result -> data;
}

int BSTMedian(struct node* root) {
	int n = count(root);
	if(n % 2 == 0) {
		int m1 = getNode(root, n / 2);
		int m2 = getNode(root, n / 2 + 1);
		return (m1 + m2) / 2;
	}
	return getNode(root, (n + 1) / 2);
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
	cout << BSTMedian(root);
	return 0;
}