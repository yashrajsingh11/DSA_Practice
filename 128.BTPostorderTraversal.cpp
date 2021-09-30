// Approach 1 : (Recursive) Keep calling a recursive function for the left of that node, then call the function for right of that node.
// Print the data. For each node it will first traverse its left and right elements then print the node.

// Approach 2 : (Iterative) Keep a stack which normally stores the left and right of the nodes. Keep another stack which has the post 
// order traversal stored in reverse order. We achieve this by pushing the normal stack top into the reverse stack after pushing its 
// left and right into the normal stack. Since the normal stack top will be right so the reverse stack will have the current node 
// then the right and then the left of the current element which is the reverse post order traversal.

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

// void postorder(struct node* root) {
// 	if(root == NULL) {
// 		return;
// 	}
// 	postorder(root -> left);
// 	postorder(root -> right);
// 	cout << root -> data << " ";
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
// 	postorder(root);
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

void postorder(struct node* root) {
	stack<struct node*> s;
	stack<int> output;
	s.push(root);
	while(!s.empty()) {
		struct node* curr = s.top();
		s.pop();
		output.push(curr -> data);
		if(curr -> left != NULL) {
			s.push(curr -> left);
		}
		if(curr -> right != NULL) {
			s.push(curr -> right);
		}
	}
	while(!output.empty()) {
		cout << output.top() << " ";
		output.pop();
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
	postorder(root);
	return 0;
}