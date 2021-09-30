// Approach 1 : (Recursive) Print the data and keep calling a recursive function for the left of that node, until it is null. Then call 
// the function for right of that node. For each node it will first print the node then traverse the left and right of the node.
// right of that node.

// Approach 2 : (Iterative) Keep pushing the root in a stack, printing value of root and updating it to the left element until it is null.
// set root to stack top, pop the stack and change root to right of root.

// ----->>> Approach 1 <<<------

// #include <iostream>

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

// void preorder(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	cout << root -> data << " ";
// 	preorder(root -> left);
// 	preorder(root -> right);
// }

// int main() {
// 	struct node* root = new node(1);
// 	root -> left = new node(2);
// 	root -> right = new node(3);
// 	root -> left -> left = new node(4);
// 	root -> right -> left = new node(5);
// 	root -> right -> right = new node(6);
// 	root -> right -> left -> left = new node(7);
// 	root -> right -> left -> right = new node(8);
// 	preorder(root);
// 	return 0;
// }

// ----->>> Approach 1 <<<------

#include <iostream>
#include <stack>

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

void preorder(struct node* root) {
	stack<struct node*> s;
	while(!s.empty() or root != NULL) {
		if(root != NULL) {
			cout << root -> data << " ";
			s.push(root);
			root = root -> left;
		}
		else {
			root = s.top();
			s.pop();
			root = root -> right;
		}
	}
}

int main() {
	struct node* root = new node(1);
	root -> left = new node(2);
	root -> right = new node(3);
	root -> left -> left = new node(4);
	root -> right -> left = new node(5);
	root -> right -> right = new node(6);
	root -> right -> left -> left = new node(7);
	root -> right -> left -> right = new node(8);
	preorder(root);
	return 0;
}