// Approach 1 : (Recursive) Keep calling a recursive function for the left of that node, then print data and call the function for right
// of that node. For each node it will first traverse the left of the node then print the node and traverse the right of the node.
// Approach 2 : (Iterative) Keep pushing the root in a stack and updating it to the left element until it is null, then print the data 
// of stack top and set root to stack top, pop the stack and change root to right of root. 

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

// void inorder(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	inorder(root -> left);
// 	cout << root -> data << " ";
// 	inorder(root -> right);
// }

// int main() {
// 	struct node* root = new node(5);
// 	root -> left = new node(6);
// 	root -> right = new node(3);
// 	root -> right -> left = new node(4);
// 	root -> right -> right = new node(2);
// 	inorder(root);
// 	return 0;
// }


// ----->>> Approach 2 <<<------

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

void inorder(struct node* root) {
	stack<struct node*> s;
	while(!s.empty() or root != NULL) {
		if(root != NULL) {
			s.push(root);
			root = root -> left;
		}
		else {
			root = s.top();
			s.pop();
			cout << root -> data << " ";
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
	inorder(root);
	return 0;
}
