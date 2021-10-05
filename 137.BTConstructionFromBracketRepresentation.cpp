// Approach : First set the first character as root and push it into stack. For every character in string we check if it is the first '('
// then we set the next character to the left of stack top and push it in. Now there can be another level in the tree, hence another '(' 
// then we again check for left and push it in stack and tree or there can be right, hence ')' and '(', then we pop the stack and set
// the next character to the right of stack top and push it in. Then for every right we again check if there is left of it or not.
// Continue this until no element is left in the string. Then the stack top is out root node.

#include <iostream>
#include <stack>
#include <string>

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
	if(root == NULL) {
		return;
	}
	cout << root -> data << " ";
	preorder(root -> left);
	preorder(root -> right);
}

struct node* construct(string A) {
	stack<struct node*> s;
	struct node* root = new node(A[0] - '0');
	s.push(root);
	int i = 1;
	while(i < A.size()) {
		if(A[i] == '(') {
			i++;
			s.top() -> left = new node(A[i] - '0');
			s.push(s.top() -> left);
			i++;
		}
		if(A[i] == ')') {
			i++;
			s.pop();
			if(A[i] == '(') {
				i++;
				s.top() -> right = new node(A[i] - '0');
				s.push(s.top() -> right);
				i++;
				if(A[i] == ')') {
					i++;
					s.pop();
				}
			}
		}
	}
	return s.top();
}

int main() {
	string A;
	cout << "Enter the Bracket Representation of Binary Tree: " << endl;
	cin >> A;
	struct node* root = construct(A);
	preorder(root);
	return 0;
}