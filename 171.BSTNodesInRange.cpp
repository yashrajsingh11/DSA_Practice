// Approach : Recursively check if the node value lies between low and high inclusive and increment count and call for both left and right child. 
// If node value is larger then call for left child, if node value is smaller then call for right child.

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

void calculate(node* root, int &count, int l, int h) {
    if(root == NULL) {
        return;
    }
    if(root -> data >= l and root -> data <= h) {
        count++;
        calculate(root -> left, count, l, h);
        calculate(root -> right, count, l, h);
    }
    else if(root -> data < l) {
        calculate(root -> right, count, l, h);
    }
    else {
        calculate(root -> left, count, l, h);
    }
}

int getCount(node *root, int l, int h) {
    int count = 0;
    calculate(root, count, l, h);
    return count;
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
	cout << getCount(root, 3, 7);
	return 0;
}